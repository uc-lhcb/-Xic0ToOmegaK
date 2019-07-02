#define Xi_c0_2017_cxx
// The class definition in Xi_c0_2017.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("Xi_c0_2017.C")
// root> T->Process("Xi_c0_2017.C","some options")
// root> T->Process("Xi_c0_2017.C+")
//

TH1 * XiDDLMassHist = nullptr;
TH1 * BackgroundSubtractedXi = nullptr;
TH1 * PrintGraph = nullptr;
TCanvas *c1 = new TCanvas("Histograms of Xi Mass", "", 720, 480);

const int TRACK_LONG = 3;
const int TRACK_DOWN = 5;

#include "fit1MeV_Gaussian.C"
#include "Xi_c0_2017.h"
#include <TH2.h>
#include <TStyle.h>

void Xi_c0_2017::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   c1->Divide(1, 1);

	XiDDLMassHist = new TH1D("Xi DDL Omega- K+", "Xi c0 MM", 100, 2100, 3200);
	BackgroundSubtractedXi = new TH1D("Entires", "DDL Cuts Using ProbNNx", 100, 2300, 3100);
	PrintGraph = new TH1D("Events", "Omega_MM Cut", 50, 1663, 1683);
	
}

void Xi_c0_2017::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t Xi_c0_2017::Process(Long64_t entry)
{
fReader.SetEntry(entry);
GetEntry(entry);

double Omega_MM_Corrected = (*Omega_MM) - (*Lambda_MM) + 1115.683;

	bool Plotter = (
		
		(Omega_MM_Corrected > 1665 && Omega_MM_Corrected < 1680)

		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)

		&&(*OmegaK_ProbNNk > 0.5)
		&&(*OmegaK_TRACK_Type == TRACK_LONG)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_DOWN)

		&&(*LambdaPi_MC15TuneV1_ProbNNpi > 0.05)
		&&(*LambdaPi_TRACK_Type == TRACK_DOWN)
		
		);

double Xic0_mass = *Xic0_MM;

	bool GoodXiDDL = (
		
		(Xic0_mass > 0)
		&&(*Xic0_PT > 2000)

		&&(Omega_MM_Corrected > 1665 && Omega_MM_Corrected < 1680)

		&&(*OmegaK_TRACK_Type == TRACK_LONG)
		&&(*OmegaK_MC15TuneV1_ProbNNk > 0.55)
		
		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)

		&&(*LambdaPr_MC15TuneV1_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_DOWN)

		&&(*LambdaPi_MC15TuneV1_ProbNNpi > 0.05)
		&&(*LambdaPi_TRACK_Type == TRACK_DOWN)

		&&(*PromptK_MC15TuneV1_ProbNNk > 0.55)
		&&(*PromptK_IPCHI2_OWNPV > 6)

		);

	bool failedXiDDL = (
		
		(Xic0_mass > 2300. && Xic0_mass < 3100.)
		&&(*Xic0_PT > 2000)
	
		&&(Omega_MM_Corrected > 1665 && Omega_MM_Corrected < 1680)

		&&(*OmegaK_TRACK_Type == TRACK_LONG)
		&&(*OmegaK_ProbNNk > 0.55)

		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_DOWN)

		&&(*LambdaPi_ProbNNpi > 0.05)
		&&(*LambdaPi_TRACK_Type == TRACK_DOWN)

		&&(*PromptK_ProbNNk > 0.55)
		&&(*PromptK_IPCHI2_OWNPV > 6)

		);

	if (GoodXiDDL)
		XiDDLMassHist->Fill(*Xic0_MM);
	
	if (failedXiDDL)
		BackgroundSubtractedXi->Fill(*Xic0_MM);

	if (Plotter)
		PrintGraph->Fill(*Omega_MM);

   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetEntry(entry);

   return kTRUE;
}

void Xi_c0_2017::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Xi_c0_2017::Terminate()
{
Double_t sigma;
Double_t deltaSigma;
Double_t mu;
Double_t deltaMu;
Double_t total;
Double_t deltaTotal;
TString sigmaStr;
TString deltaSigmaStr;
TString deltaTotalStr;
TString muStr;
TString deltaMuStr;
TString totalStr;

TF1 *myXifit = new TF1("myXifit", fit1MeV_Gaussian, 2300, 3100, 5);
myXifit->SetParameter(0, 70);
myXifit->SetParameter(1, 2471);
myXifit->SetParameter(2, 40);
myXifit->SetParLimits(2, 0., 20.);
myXifit->SetParameter(3, 10.);
myXifit->SetParameter(4, 0.);

c1->cd(1);
XiDDLMassHist->GetXaxis()->SetTitle("MeV");
XiDDLMassHist->GetYaxis()->SetTitle("Events Per Mev");
XiDDLMassHist->SetMinimum(0);
XiDDLMassHist->Draw();
c1->SaveAs("Xi_c0_Graph_2017_4.png");

c1->cd(2);
BackgroundSubtractedXi->GetXaxis()->SetTitle("MeV");
BackgroundSubtractedXi->GetYaxis()->SetTitle("Events Per 8 Mev");
BackgroundSubtractedXi->SetMinimum(0);
BackgroundSubtractedXi->Draw();
c1->SaveAs("Xi_c0_Graphs_2017_3.png");

PrintGraph->GetXaxis()->SetTitle("MeV");
PrintGraph->GetYaxis()->SetTitle("Events per 0.4 MeV");
//PrintGraph->Draw();
//c1.SaveAs("Omega_MM_CorrectedM_Cut.png");
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
