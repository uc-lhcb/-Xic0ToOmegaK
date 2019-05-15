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
TH1 * strippingLevelXiDDDMassHist = nullptr;
TH1 * strippingLevelXiLLLMassHist = nullptr;
TH1 * strippingLevelXiDLLMassHist = nullptr;
TH1 * backgroundsubtractedXi = nullptr;

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
	strippingLevelXiLDDMassHist = new TH1D("XiLDD, Omega- K+", "LDD: Stripping Level Cuts", 100, 2320, 3100);
	strippingLevelXiDDDMassHist = new TH1D("XiDDD, Omega- K+", "DDD: Stripping Level Cuts", 100, 2320, 3100);
	strippingLevelXiLLLMassHist = new TH1D("XiLLL, Omega- K+", "LLL: Stripping Level Cuts", 100, 2320, 3100);
	strippingLevelXiDLLMassHist = new TH1D("XiDLL Omega- K+", "DLL: StrippingLevel Cuts", 100, 2320, 3100);
	backgroundsubtractedXi = new TH1D("Background Noise", "Xi LL Background Subtracted", 100, 2320, 3100);
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
double Xic0_mass = *Xi_c0_MM;
	
	bool GoodXiLDD = (

		(Xic0_mass > 2300. && Xic0_mass < 3100.)
		//&&(*Xi_c0_IPCHI2_OWNPV > 0)
		//&&(*Xi_c0_IPCHI2_OWNPV < 5)

		//&&(*Omega_MM > 1665 && *Omega_MM < 1680)
		//&&(*Omega_IPCHI2_OWNPV > 0)
		//&&(*Omega_IPCHI2_OWNPV < 20)
		
		//&&(*OmegaK_TRACK_Type == TRACK_LONG)
		//&&(*OmegaK_ProbNNk > 0.5)
		
		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
		&&(*Lambda_IPCHI2_OWNPV > 0)
		&&(*Lambda_IPCHI2_OWNPV < 400)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_DOWN)

		&&(*LambdaPi_ProbNNpi > 0.05)	
		&&(*LambdaPi_TRACK_Type == TRACK_DOWN)

		);
	
	bool GoodXiDDD = (
		
		(Xic0_mass > 2300. && Xic0_mass < 3100)
		&&(*Xi_c0_IPCHI2_OWNPV > 0)
		&&(*Xi_c0_IPCHI2_OWNPV < 5)

		&&(*Omega_MM > 1665 && *Omega_MM < 1680)
		&&(*Omega_IPCHI2_OWNPV > 0)
		&&(*Omega_IPCHI2_OWNPV < 20)

		&&(*OmegaK_TRACK_Type == TRACK_DOWN)
		&&(*OmegaK_ProbNNk > 0.5)

		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
		&&(*Lambda_IPCHI2_OWNPV > 0)
		&&(*Lambda_IPCHI2_OWNPV < 500)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_DOWN)

		&&(*LambdaPi_ProbNNpi > 0.1)
		&&(*LambdaPi_TRACK_Type == TRACK_DOWN)
	
		);

	bool GoodXiLLL = (
		
		(Xic0_mass > 2300. && Xic0_mass < 3100)
		&&(*Xi_c0_IPCHI2_OWNPV > 0)
		&&(*Xi_c0_IPCHI2_OWNPV < 5)

		&&(*Omega_MM > 1665 && *Omega_MM < 1680)
		&&(*Omega_IPCHI2_OWNPV > 0)
		&&(*Omega_IPCHI2_OWNPV < 20)

		&&(*OmegaK_TRACK_Type == TRACK_LONG)
		&&(*OmegaK_ProbNNk > 0.5)

		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
		&&(*Lambda_IPCHI2_OWNPV > 0)
		&&(*Lambda_IPCHI2_OWNPV < 500)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_LONG)

		&&(*LambdaPi_ProbNNpi > 0.1)
		&&(*LambdaPi_TRACK_Type == TRACK_LONG)
		
		);

	bool GoodXiDLL = (
		
		(Xic0_mass > 2300. && Xic0_mass < 3100)
		&&(*Xi_c0_IPCHI2_OWNPV > 0)
		&&(*Xi_c0_IPCHI2_OWNPV < 5)

		&&(*Omega_MM > 1665 && *Omega_MM < 1680)
		&&(*Omega_IPCHI2_OWNPV > 0)
		&&(*Omega_IPCHI2_OWNPV < 20)

		&&(*OmegaK_TRACK_Type == TRACK_DOWN)
		&&(*OmegaK_ProbNNk > 0.5)

		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
		&&(*Lambda_IPCHI2_OWNPV > 0)
		&&(*Lambda_IPCHI2_OWNPV < 500)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_LONG)

		&&(*LambdaPi_ProbNNpi > 0.1)
		&&(*LambdaPi_TRACK_Type == TRACK_LONG)
		
		);




	bool SubtractedXiLL = (
		(Xic0_mass > 2300. && Xic0_mass < 3100.)
		&&(*Xi_c0_FDCHI2_OWNPV > 33)
		&&(*Xi_c0_FDCHI2_OWNPV < 50)
		&&(*Omega_MM > 1650 && *Omega_MM < 1665)
		&&(*Omega_MM > 1680 && *Omega_MM < 1698)
		&&(*OmegaK_ProbNNe > 0.05)
		&&(*OmegaK_ProbNNe < 1)
		&&(*OmegaK_ProbNNpi > 0.1)
		&&(*OmegaK_ProbNNpi < 1)
		&&(*OmegaK_ProbNNghost > 0.1)
		&&(*OmegaK_ProbNNghost < 1)
		&&(*OmegaK_ProbNNk > 0)
		&&(*OmegaK_ProbNNk < 0.6)
		);
		

	if (GoodXiLDD)
		strippingLevelXiLDDMassHist->Fill(*Xi_c0_MM);
	
	if (GoodXiLLL)
		strippingLevelXiLLLMassHist->Fill(*Xi_c0_MM);
	
	if (GoodXiDLL)
		strippingLevelXiDLLMassHist->Fill(*Xi_c0_MM);

	if (GoodXiDDD)
		strippingLevelXiDDDMassHist->Fill(*Xi_c0_MM);

	if (SubtractedXiLL)
		backgroundsubtractedXi->Fill(*Xi_c0_MM);


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
TCanvas c1;
strippingLevelXiLDDMassHist->Draw();
//backgroundSubtractedXi->Draw();
c1.SaveAs("Xi_c0_fit.png");
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
