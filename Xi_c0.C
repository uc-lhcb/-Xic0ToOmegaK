#define Xi_c0_cxx
// The class definition in Xi_c0.h has been generated automatically
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
// root> T->Process("Xi_c0.C")
// root> T->Process("Xi_c0.C","some options")
// root> T->Process("Xi_c0.C+")
//

TH1 * strippingLevelXiLDDMassHist = nullptr;
TH1 * backgroundsubtractedXi = nullptr;
TH1 * PrintGraph = nullptr;
TCanvas *c1 = new TCanvas('Histograms of Xi Mass", "", 750, 500);

const int TRACK_LONG = 3;
const int TRACK_DOWN = 5;

#include "fit1MeV_Gaussian.C"
#include "Xi_c0.h"
#include <TH2.h>
#include <TStyle.h>

void Xi_c0::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
	strippingLevelXiLDDMassHist = new TH1D("XiLDD, Omega- K+", "LDD: Stripping Level Cuts", 100, 2300, 3100);
	backgroundsubtractedXi = new TH1D("Background Noise", "Xi LL Background Subtracted", 100, 2320, 3100);
	PrintGraph = new TH1D("Events", "Omega_MM Cut", 50, 1663, 1683);
	c1->Divide(2,1);
}

void Xi_c0::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t Xi_c0::Process(Long64_t entry)
{
fReader.SetEntry(entry);
GetEntry(entry);
	
double Omega_MM_Corrected = (*Omega_MM) - (*Lambda_MM) + 1115.683;
	
double Omega_mass = *Omega_MM;
	
	bool Plotter = (
		 
		(Omega_mass > 1665 && Omega_mass < 1680)
		
		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
		
		&&(*OmegaK_ProbNNk > 0.5)
		&&(*OmegaK_TRACK_Type == TRACK_LONG)
		
		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_DOWN)
		
		&&(*LambdaPi_ProbNNpi > 0.05)
		&&(*LambdaPi_TRACK_Type == TRACK_DOWN)
		);
	
double Xic0_mass = *Xi_c0_MM;
	
	bool GoodXiLDD = (

		(Xic0_mass > 2300. && Xic0_mass < 3100.)
		&&(*Xi_c0_PT > 1750)
		
		&&(Omega_MM_Corrected > 1665 && Omega_MM_Corrected < 1680)
		
		&&(*OmegaK_TRACK_Type == TRACK_LONG)
		&&(*OmegaK_ProbNNk > 0.55)
		
		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_DOWN)

		&&(*LambdaPi_ProbNNpi > 0.05)	
		&&(*LambdaPi_TRACK_Type == TRACK_DOWN)
		
		&&(*PromptPi_ProbNNk > 0.55)
		&&(*PromptPi_IPCHI2_OWNPV > 9)

		);
	
	bool badXiLDD = (
	
		(Xic0_mass > 2300. && Xic0_mass < 3100.)
		
		&&(*Omega_MM_Corrected > 1665 && *Omega_MM_Corrected < 1680)
		
		&&(*OmegaK_TRACK_Type == TRACK_LONG)
		&&(*OmegaK_ProbNNk > 0.55)
		
		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_DOWN)

		&&(*LambdaPi_ProbNNpi > 0.05)	
		&&(*LambdaPi_TRACK_Type == TRACK_DOWN)

		&&(*PromptPi_ProbNNk > 0.55)
		&&(*PromptPi_IPCHI2_OWNPV < 9)
		
		);
	
		

	if (GoodXiLDD)
		strippingLevelXiLDDMassHist->Fill(*Xi_c0_MM);

	if (SubtractedXiLL)
		backgroundsubtractedXi->Fill(*Xi_c0_MM);
	
	if (Plotter)
		PrintGraph->Fill(*Omega_MM)


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

   return kTRUE;
}

void Xi_c0::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Xi_c0::Terminate()
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
myXifit->SetParameter(0,40);
myXifit->SetParameter(1, 2470);
myXifit->SetParameter(2, 16);
myXifit->SetParLimits(2, 0., 20.);
myXifit->SetParameter(3, 0.);
myXiFit->SetParameter(4, 0.);

c1->cd(1);
strippingLevelXiLDDMassHist->GetXaxis()->SetTitle("MeV");
strippingLevelXiLDDMassHist->GetYaxis()->SetTitle("Events Per 8 MeV");
strippingLevelXiLDDMassHist->SetMinimum(0);
strippingLevelXiLDDMassHist->Fit("myXifit");
c1.SaveAs("Xi_c0_fit.png");

c1->cd(2);
backgroundSubtractedXi->GetXaxis()->SetTitle("MeV");
backgroundsubtractedXi->GetYaxis()->SetTitle("Events Per 6 Mev");
backgroundsubtractedXi->SetMinimum(0);
backgroundsubtractedXi->Draw();
c1.SaveAs("TotalSubtraction.png");

PrintGraph->GetXaxis()->SetTitle("MeV");
PrintGraph->GetYaxis()->SetTitle("Events per 0.4 MeV");
//PrintGraph->Draw();
//c1.SaveAs("Omega_MM_Cut2.png");
	

   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
