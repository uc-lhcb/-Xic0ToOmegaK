#define OneD_Multivariate_cxx


#include "OneD_Multivariate.h"
#include <TH2.h>
#include <TStyle.h>
#include "fit1MeV_Gaussian.C"

#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TF1.h>

#include <vector>
#include <algorithm>
#include <functional>
#include <chrono>
#include <thread>
#include <array>

std::array<std::array<double, 30>, 30> fomKSignal;
std::array<std::array<double, 30>, 30> fomKBackground;
std::array<std::array<double, 30>, 30> fomK;

TH2D * FigureK  = nullptr;
TH2D * SignalKPlot = nullptr;
TH2D * BackgroundKPlot = nullptr;
TH1D * FOMKaon = nullptr;
TH1D * HistogramK3 = nullptr;
TH1D * HistogramK4 = nullptr;
TH1D * HistogramK5 = nullptr;
TH1D * HistogramK7 = nullptr;
TH1D * HistogramK9 = nullptr;

TH1D * TwoDimensional = nullptr;
TH1D * TwoDimensional2 = nullptr;


TFile * File = nullptr;
TCanvas * c1 = nullptr;

void OneD_Multivariate::Begin(TTree * /*tree*/)
{

   TString option = GetOption();
}

void OneD_Multivariate::SlaveBegin(TTree * /*tree*/)
{
TString option = GetOption();

SignalKPlot = new TH2D("Figure of Merit", "Color Plot of Xic0 Mass - Signal*Signal", 30, 0.7, 3.7, 30, 0.4, 1.0);
SignalKPlot->GetXaxis()->SetTitle("Log(PromptK_IPCHI2_OWNPV)");
SignalKPlot->GetYaxis()->SetTitle("PromptK_MC15TuneV1_ProbNNk");
SignalKPlot->GetZaxis()->SetTitle("Signal*Signal");

BackgroundKPlot = new TH2D("Figures of Merit", "Color Plot of Xic0 Mass - Background*Background", 30, 0.7, 3.7, 30, 0.4, 1.0);
BackgroundKPlot->GetXaxis()->SetTitle("Log(PromptK_IPCHI2_OWNPV)");
BackgroundKPlot->GetYaxis()->SetTitle("PromptK_MC15TuneV1_PrbNNk");
BackgroundKPlot->GetZaxis()->SetTitle("Background*Background");

FigureK = new TH2D("Figures of Merit", "Color Plot of Xic0 Mass - One Dimensional Projection", 30, 0.7, 3.7, 30, 0.4, 1.0);
FigureK->GetXaxis()->SetTitle("Log(PromptK_IPCHI2_OWNPV)");
FigureK->GetYaxis()->SetTitle("PromptK_MC15TuneV1_ProbNNk");
FigureK->GetZaxis()->SetTitle("Signal*Signal/Background*Background");

  HistogramK3 = new TH1D("Figures of Merit", "Mass of Xic0 - FOM Kaon > 0.3", 100, 2370, 2570);
   HistogramK3->GetXaxis()->SetTitle("MeV");
   HistogramK3->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramK4 = new TH1D("Figures of Merit", "Mass of Xic0 - FOM Kaon > 0.4", 100, 2370, 2570);
   HistogramK4->GetXaxis()->SetTitle("MeV");
   HistogramK4->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramK5 = new TH1D("Figures of Merit", "Mass of Xic0 - FOM Kaon > 0.5", 100, 2370, 2570);
   HistogramK5->GetXaxis()->SetTitle("MeV");
   HistogramK5->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramK7 = new TH1D("Figures of Merit", "Mass of Xic0- FOM Kaon > 0.7", 100, 2370, 2570);
   HistogramK7->GetXaxis()->SetTitle("MeV");
   HistogramK7->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramK9 = new TH1D("Figures of Merit", "Mass of Xic0 - FOM Kaon > 0.9", 100, 2370, 2570);
   HistogramK9->GetXaxis()->SetTitle("MeV");
   HistogramK9->GetYaxis()->SetTitle("Events Per 2 MeV");

TwoDimensional = new TH1D("Figures of Merit", "Mass of Xic0 - FOM Kaon > 0.25", 100, 2370, 2570);
TwoDimensional->GetXaxis()->SetTitle("MeV");
TwoDimensional->GetYaxis()->SetTitle("Events per 2 MeV");

TwoDimensional2 = new TH1D("Figures of Merit", "Mass of Xic0 - FOM Kaon > 0.1", 100, 2370, 2570);
TwoDimensional2->GetXaxis()->SetTitle("MeV");
TwoDimensional2->GetYaxis()->SetTitle("Events per 2 Mev");

FOMKaon = new TH1D("Figure of Merit", "Frequency of Kaon S:B FOMs", 100, 0, 2);
FOMKaon->GetXaxis()->SetTitle("FOM");
FOMKaon->GetYaxis()->SetTitle("Events Per 0.2 S:B");

File = new TFile("1DColorPlotWithHistogram.root", "RECREATE");
gFile = File;

c1 = new TCanvas("canvas", "Test Canvas");

for (double i = 0; i < 30; i++){
   for (double j = 0; j < 30; j++){

      double x = 0.75 + (0.1 * i); //wrong values
      double y = 0.41 + (0.02 * j); //wrong values

      double SignalK = (199.86 + TMath::Exp(10.47 - (1.68 * x))) * (231.32 + TMath::Exp(-16.11 + (25.025 * y)));
      double BackgroundK = (111.07 + TMath::Exp(10.537 - (28.43 * x))) * (581.09 + TMath::Exp(-9.727 + (17.81 * y)));
      fomK[i][j] = (SignalK / BackgroundK);
      fomKSignal[i][j] = SignalK;
      fomKBackground[i][j] = BackgroundK;

   }
}

}

Bool_t OneD_Multivariate::Process(Long64_t entry)
{
   GetEntry(entry);
   fReader.SetEntry(entry);

   double Omega_MM_Corrected = (*Omega_MM) - (*Lambda_MM) + 1115.683;

   bool KaonCuts = (
      (TMath::Log10(*PromptK_IPCHI2_OWNPV) > 0.6)
      &&(Omega_MM_Corrected > 1665 && Omega_MM_Corrected < 1680)
   );

   bool GeneralCuts = (
      (*Lambda_MM > 1112 && *Lambda_MM)
      &&(*Xi_c0_PT > 1500)
   );

for (double i = 0; i < 30; i++){
   for (double j = 0; j < 30; j++){

      double x = 0.75 + (0.1 * i);
      double y = 0.41 + (0.02 * j);

      if(fomK[i][j] > 0.3) {

         double xt = x;
         double yt = y;

            if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xt - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xt + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yt - 0.01)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yt + 0.01)) && KaonCuts)
               HistogramK3->Fill(*Xi_c0_MM);}

      if(fomK[i][j] > 0.4) {

               
         double xtt = x;
         double ytt = y;
            if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xtt - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xtt + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (ytt - 0.01)) && ((*PromptK_MC15TuneV1_ProbNNk) < (ytt + 0.01)) && KaonCuts)
               HistogramK3->Fill(*Xi_c0_MM);}

      if(fomK[i][j] > 0.5) {

            double xx = x;
            double yy = y;
               if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xx - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xx + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yy - 0.01)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yy + 0.01)) && KaonCuts)
               HistogramK3->Fill(*Xi_c0_MM);}

      if(fomK[i][j] > 0.7) {

            double xxx = x;
            double yyy = y;
               if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xxx - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xxx + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yyy - 0.01)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yyy + 0.01)) && KaonCuts)
               HistogramK3->Fill(*Xi_c0_MM);}

      if(fomK[i][j] > 0.9) {

            double xxxx = x;
            double yyyy = y;
               if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xxxx - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xxxx + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yyyy - 0.01)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yyyy + 0.01)) && KaonCuts)
               HistogramK3->Fill(*Xi_c0_MM);}
      }
}

   fReader.SetLocalEntry(entry);

   return kTRUE;
}

void OneD_Multivariate::SlaveTerminate()
{


}

void OneD_Multivariate::Terminate()
{
for (double i = 0; i < 30; i++){
   for (double j = 0; j < 30; j++){

      double x = 0.75 + (0.1 * i);
      double y = 0.41 + (0.02 * j);

         FOMKaon->Fill(fomK[i][j]);
         FigureK->Fill(x, y, fomK[i][i]);
         SignalKPlot->Fill(x, y, fomKSignal[i][j]);
         BackgroundKPlot->Fill(x, y, fomKBackground[i][j]);

   }
}  
TF1 * myXifit = new TF1("myXifit", fit1MeV_Gaussian, 2300, 3100, 5);
myXifit->SetParameter(0, 70);
myXifit->SetParameter(1, 2471);
myXifit->SetParameter(2, 40);
myXifit->SetParLimits(2, 0., 20.);
myXifit->SetParameter(3, 10);
myXifit->SetParameter(4, 0);

FigureK->Draw("COLZ");
c1->Write("Kaon Color Plot");

SignalKPlot->Draw("COLZ");
c1->Write("Kaon Color Plot - Signal");

BackgroundKPlot->Draw("COLZ");
c1->Write("Kaon Color Plot - Background");

HistogramK3->Fit("myXifit");
HistogramK3->SetMinimum(0);
c1->Write("Kaon 0.3");

HistogramK4->Fit("myXifit");
HistogramK4->SetMinimum(0);
c1->Write("Kaon 0.4");

HistogramK5->Fit("myXifit");
HistogramK5->SetMinimum(0);
c1->Write("Kaon 0.5");

HistogramK7->Fit("myXifit");
HistogramK7->SetMinimum(0);
HistogramK7->Write("Kaon 0.7");

HistogramK9->Fit("Kaon 0.9");
HistogramK9->SetMinimum(0);
HistogramK9->Write("Kaon 0.9");

TwoDimensional->Fit("myXifit");
TwoDimensional->SetMinimum(0);
c1->Write("Two Dimensional 0.25");

TwoDimensional2->Fit("myXifit");
TwoDimensional2->SetMinimum(0);
TwoDimensional2->Write("Two Dimensional 0.1");

FOMKaon->Draw();
c1->Write("Kaon FOMs");

File->Close();

}
