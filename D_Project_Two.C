#define D_Project_Two_cxx

#include "D_Project_Two.h"
#include <TH2.h>
#include <TStyle.h>

TCanvas *c1 = new TCanvas("Background Subtraction", "Histograms", 1000, 500);
TFile * File = nullptr;

TH1 *IPCHI2Signal = nullptr;
TH1 *IPCHI2bkgd = nullptr;

TH1 *ProbSignal = nullptr;
TH1 *Probbkgd = nullptr;

TH1 *IPCHI2SignalEstimate = nullptr;
TH1 *ProbSignalEstimate = nullptr;

double UB1 = 1.;
double LB1 = 0.4;
const int Bin1 = 12;

double UB2 = 4;
double LB2 = 0.7;
const int Bin2 = 28;

void D_Project_Two::Begin(TTree * /*tree*/)
{

   TString option = GetOption();
}

void D_Project_Two::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

   File = new TFile("1DProjectionKaon.root", "RECREATE");
   gFile = File;

   TH1::SetDefaultSumw2(kTRUE);

   ProbSignal = new TH1D("Probability", "Signal Region", Bin1, LB1, UB1);
   Probbkgd = new TH1D("Probability", "Background Region", Bin1, LB2, UB1);
   ProbSignalEstimate = new TH1D("Probability", "Signal Estimation", Bin1, LB1, UB1);

   IPCHI2Signal = new TH1D("IPCHI2", "Signal Region", Bin2, LB2, UB2);
   IPCHI2bkgd = new TH1D("IPCHI2", "Background Region", Bin2, LB2, UB2);
   IPCHI2SignalEstimate = new TH1D("IPCHI2", "Signal Estimation", Bin2, LB2, UB2);

   ProbSignal->SetLineColor(kBlue);
   Probbkgd->SetLineColor(kRed);
   ProbSignalEstimate->SetLineColor(kGreen+3);
   IPCHI2Signal->SetLineColor(kBlue);
   IPCHI2bkgd->SetLineColor(kRed);
   IPCHI2SignalEstimate->SetLineColor(kGreen+3);
   
}

Bool_t D_Project_Two::Process(Long64_t entry)
{

   fReader.SetLocalEntry(entry);
   GetEntry(entry);

   double Omega_MM_Corrected = (*Omega_MM) - (*Lambda_MM) + 1115.683;

   bool MassCuts = (
      (*Xi_c0_MM > 2370 && *Xi_c0_MM < 2570)
      &&(Omega_MM_Corrected > 1665 && Omega_MM_Corrected < 1680)
      &&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
   );

   bool PreliminaryCuts = (
      (*Xi_c0_PT > 1500)
      //&&(TMath::Log10(*PromptK_IPCHI2_OWNPV) > 0.6)
      //&&(TMath::Log10(*PromptK_IPCHI2_OWNPV)> 0.6)
   );

bool SignalRegion = *Xi_c0_MM > 2460 && *Xi_c0_MM < 2486;
bool BackgroundRegion = (*Xi_c0_MM > 2400 && *Xi_c0_MM < 2413) || (*Xi_c0_MM > 2540 && *Xi_c0_MM < 2553);
   
if (SignalRegion && PreliminaryCuts && MassCuts)
   IPCHI2Signal->Fill(TMath::Log(*PromptK_IPCHI2_OWNPV));

if (BackgroundRegion && PreliminaryCuts && MassCuts)
   IPCHI2bkgd->Fill(TMath::Log10(*PromptK_IPCHI2_OWNPV));

if (SignalRegion && PreliminaryCuts && MassCuts)
   ProbSignal->Fill(*PromptK_MC15TuneV1_ProbNNk);

if (BackgroundRegion && PreliminaryCuts && MassCuts)
   Probbkgd->Fill(*PromptK_MC15TuneV1_ProbNNk);

ProbSignalEstimate->Add(ProbSignal, Probbkgd, 1.0, -1.0);
IPCHI2SignalEstimate->Add(IPCHI2Signal, IPCHI2bkgd, 1.0, -1.0);

   return kTRUE;
}

void D_Project_Two::SlaveTerminate()
{
}

void D_Project_Two::Terminate()
{
	
   //TF1 *ProbSignalFit = new TF1("f1", "[0] + exp([1] + [2]*x)", 0.4, 1.);
   //ProbSignalFit->SetParLimits(2, 0., 30.);

   TF1 *IPCHI2BackgroundFit = new TF1("f2", "[0] + exp([1] + [2]*x)", 1.4, 4);
   IPCHI2BackgroundFit->SetParLimits(2, -5., 0.);

   TF1 *IPCHI2SignalFit = new TF1("f3", "[0] + exp([1]+[2]*x)", 1.4, 4);
   //IPCHI2SignalFit->SetParLimits(2, -5, -1);

   IPCHI2SignalEstimate->SetMaximum(10000);
   IPCHI2SignalEstimate->SetMinimum(0);
   //ProbSignalEstimate->SetMaximum(3000);

   IPCHI2SignalEstimate->Fit("f3", "R");
   IPCHI2SignalEstimate->GetFunction("f3")->SetLineColor(kGreen+3);
   IPCHI2bkgd->Fit("f2");
   IPCHI2bkgd->GetFunction("f2")->SetLineColor(kRed);
   //ProbSignalEstimate->Fit("f1");
   //ProbSignalEstimate->GetFunction("f1")->SetLineColor(kGreen+3);
   //Probbkgd->Fit("f1");
   //Probbkgd->GetFunction("f1")->SetLineColor(kRed);

   gStyle->SetOptTitle(0);
   TPaveText *t1 = new TPaveText(0.3, 0.91, 0.7, 1.0, "brNDC");
   t1->AddText("Signal and Background Estimation for Promptk_IPCHI2_OWNPV");
   //TPaveText *t2 = new TPaveText(0.3, 0.91, 0.7, 1.0, "brNDC");
   //t2->AddText("Signal and Background Estimation for Promptk_MC15TuneV1_ProbNNk");

      IPCHI2SignalEstimate->Draw();
      IPCHI2Signal->Draw("SAME");
      IPCHI2bkgd->Draw("SAME");
      t1->Draw("SAME");
      IPCHI2SignalEstimate->GetYaxis()->SetTitle("Events per mm");
      IPCHI2SignalEstimate->GetXaxis()->SetTitle("IPCHI2");
      gPad->BuildLegend(0.78, 0.75, 0.98, 0.95);
      c1->Write("IPCHI2 Estimations");

      //c1->Clear();
      //ProbSignalEstimate->Draw();
      //ProbSignal->Draw("SAME");
      //Probbkgd->Draw("SAME");
      //t2->Draw("SAME");
      //ProbSignalEstimate->GetYaxis()->SetTitle("Events per mm");
      //ProbSignalEstimate->GetXaxis()->SetTitle("Probability");
      //gPad->BuildLegend(0.79, 0.75, 0.98, 0.95);
      //c1->Write("Prob Estimations");
      c1->SaveAs("1D_Projection_010.png");
}
