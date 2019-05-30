#define Xic0_2016_cxx
// The class definition in Xic0_2016.h has been generated automatically
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
// root> T->Process("Xic0_2016.C")
// root> T->Process("Xic0_2016.C","some options")
// root> T->Process("Xic0_2016.C+")
//

TH1 * strippingLevelXiDDLMassHist = nullptr; 
TH1 * LambdaM = nullptr;
TH1 * OmegaM = nullptr;
TH1 * zoomhist = nullptr;

TH1 * LambdaSignal = nullptr;
TH1 * LambdaLowerBand = nullptr;
TH1 * LambdaUpperBand = nullptr;
TH1 * BandSignals = nullptr;
TH1 * TotalSignals = nullptr;

//failed experimenting but possible future use
//TCanvas *c1 = new TCanvas("Background Subtraction", "Histograms", 1000, 500);
//THStack *hs = new THStack("hs", "Background Subtracted Lambda Mass");

#include "fit1MeV_Gaussian.C"
#include "Xic0_2016.h"
#include <TH2.h>
#include <TStyle.h>

const int TRACK_LONG = 3;
const int TRACK_DOWN = 5;

void Xic0_2016::Begin(TTree * /*tree*/)
{
	strippingLevelXiDDLMassHist = new TH1D("Xi DDL, Omega- K+", "LLL Cuts", 100, 2150, 3150);
	LambdaM = new TH1D("Lambda, Pi Pr", "Lambda Mass", 100, 1090, 1140);
	OmegaM = new TH1D("Omega: Lambda, K-", "Omega- Mass", 100, 1640, 1710);
	zoomhist = new TH1D("Stats", "Zoomed Hist", 100, 0, 20);

	//failed experimenting but possible future use
	//LambdaSignal = new TH1D("Signal Region - Lambda", "Background Mass", 100, 1112, 1119);
	//LambdaLowerBand = new TH1D("Lower Signal Region - Lambda", "Lower Band Mass", 100, 1090, 1112);
	//LambdaUpperBand = new TH1D("Upper Signal Region - Lambda", "Upper Band Mass", 100, 1119, 1140);
	//BandSignals = new TH1D("Band Signals", "Band Mass Signals", 100, 1090, 1140);
	//TotalSignals = new TH1D("Lambda Mass", "Background Adjusted Lambda Mass", 100, 1090, 1140);

   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void Xic0_2016::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t Xic0_2016::Process(Long64_t entry)
{
fReader.SetEntry(entry);
GetEntry(entry);

	
//failed experimenting but possible future use
//bool SignalRegion = *Lambda_MM > 1112 && *Lambda_MM < 1119;
//bool LowerSignalRegion = *Lambda_MM > 1090 && *Lambda_MM < 1112;
//bool UpperSignalRegion = *Lambda_MM > 1119 && *Lambda_MM < 1140;

	//if (SignalRegion)
	//	LambdaSignal->Fill(*Lambda_MM);
	//if (LowerSignalRegion)
	//	LambdaLowerBand->Fill(*Lambda_MM);
	//if (UpperSignalRegion)
	//	LambdaUpperBand->Fill(*Lambda_MM);
		
//BandSignals->Add(LambdaLowerBand, LambdaUpperBand, 1.0, 1.0);
//TotalSignals->Add(LambdaSignal, BandSignals, 1.0, -0.5);

	//bool Signal = (
		//(*TotalSignals > 1105 && *TotalSignals < 1125)
		//&&(*LambdaPr_TRACK_Type == TRACK_DOWN)
		//&&(*LambdaPr_ProbNNp > 0.2)

		//&&(*LambdaPi_TRACK_Type == TRACK_DOWN)
		//&&(*LambdaPi_ProbNNpi > 0.01)
		//);

//used this to zoom in on histograms
double Xic0_IPCHI = *PromptPi_IPCHI2_OWNPV;
	bool zoomed = (
	(Xic0_IPCHI > 0 && Xic0_IPCHI < 20)
	);
	
//Lambda Cuts	
double Lambda_M = *Lambda_MM;

	bool LambdaMass = (
	(*Lambda_MM > 1112 && *Lambda_MM < 1119)
	//&&(*Lambda_IPCHI2_OWNPV > 0 && *Lambda_IPCHI2_OWNPV < 3)
	
	&&(*LambdaPr_TRACK_Type == TRACK_DOWN)
	&&(*LambdaPr_ProbNNp > 0.2)
	&&(*LambdaPr_ID > 2200 && *LambdaPr_ID < 2300)
	
	&&(*LambdaPi_TRACK_Type == TRACK_DOWN)
	&&(*LambdaPi_ProbNNpi > 0.01)
	&&(*LambdaPi_ID < 0)
	
	);

//Omega Cuts
double Omega_M = *Omega_MM;

	bool OmegaMass = (
	(*Omega_MM > 1666 && *Omega_MM < 1678)
	
	&&(*OmegaK_TRACK_Type == TRACK_LONG)
	&&(*OmegaK_ProbNNk > 0.95)
	&&(*OmegaK_ID < 0)

	&&(*Lambda_MM > 1112 && *Lambda_MM < 1119)
	&&(*LambdaPr_TRACK_Type == TRACK_DOWN)
	&&(*LambdaPr_ProbNNp > 0.2)

	&&(*LambdaPi_TRACK_Type == TRACK_DOWN)
	&&(*LambdaPi_ProbNNpi > 0.01)
	);	

//Xi_c0 Cuts
double Xic0_mass = *Xi_c0_MM;

	bool GoodXiDDL = (
	(Xic0_mass > 2300. && Xic0_mass < 3100)
	//&&(*Xi_c0_IPCHI2_OWNPV > 0 && *Xi_c0_IPCHI2_OWNPV < 0.5)
	
	&&(*Lambda_MM > 1112 && *Lambda_MM < 1119)
	&&(*LambdaPr_TRACK_Type == TRACK_LONG)
	&&(*LambdaPr_ProbNNp > 0.2)
	&&(*LambdaPr_ID > 2200 && *LambdaPr_ID < 2300)	

	&&(*LambdaPi_TRACK_Type == TRACK_LONG)
	&&(*LambdaPi_ProbNNpi > 0.01)
	&&(*LambdaPi_ID < 0)

	&&(*Omega_MM > 1666 && *Omega_MM < 1678)

	&&(*OmegaK_TRACK_Type == TRACK_LONG)
	&&(*OmegaK_ProbNNk > 0.95)
	&&(*OmegaK_ID < 0)

	&&(*PromptPi_ProbNNk > 0.2)
	&&(*PromptPi_ID > 0)
	&&(*PromptPi_IPCHI2_OWNPV > 0 && *PromptPi_IPCHI2_OWNPV < 20)
	);

	if (GoodXiDDL)
		strippingLevelXiDDLMassHist->Fill(*Xi_c0_MM);
	if (LambdaMass)
		LambdaM->Fill(*Lambda_MM);
	if (OmegaMass)
		OmegaM->Fill(*Omega_MM);
	if (zoomed)
		zoomhist->Fill(*Xi_c0_IPCHI2_OWNPV);

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

void Xic0_2016::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Xic0_2016::Terminate()
{
TCanvas c1;
strippingLevelXiDDLMassHist->GetXaxis()->SetTitle("MeV");
strippingLevelXiDDLMassHist->GetYaxis()->SetTitle("Events Per 8 MeV");
strippingLevelXiDDLMassHist->Draw();
c1.SaveAs("Xic0_MM_2016LLL.png");

zoomhist->GetXaxis()->SetTitle("mm");
zoomhist->GetYaxis()->SetTitle("Events");
//zoomhist->Draw();
//c1.SaveAs("Xi_c0_IPCHI2_OWNPV_Zoomed.png");

LambdaM->GetXaxis()->SetTitle("Mev");
LambdaM->GetYaxis()->SetTitle("Events per 10 MeV");
//LambdaM->Draw();
//c1.SaveAs("Lambda_M_20161.png");

OmegaM->GetXaxis()->SetTitle("MeV");
OmegaM->GetYaxis()->SetTitle("Events per 10 MeV");
//OmegaM->Draw();
//c1.SaveAs("Omega_M_2016.png");

//hs->Add(BandSignals);
//hs->Add(TotalSignals);
//hs->Draw("nostack");
//hs->GetXaxis()->SetTitle("Lambda Mass");
//hs->GetYaxis()->SetTitle("Events");
//c1.SaveAs("LambdaMass20161.png");

//TotalSignals->Draw();
//c1.SaveAs("LambdaMass20161.png");

c1.Modified();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
