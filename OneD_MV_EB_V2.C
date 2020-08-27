#define OneD_MV_EB_V2_cxx

#include "OneD_MV_EB_V2.h"
#include <TH2.h>
#include <TStyle.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TF1.h>
#include "fit1MeV_Gaussian.C"
#include "CrystalBall.C"

using namespace std;

#include <vector>
#include <algorithm>
#include <functional>
#include <chrono>
#include <thread>
#include <array>

	//DEFINING VARIABLES//

std::array<std::array<double, 50>, 50> fomK;		//Nested Array For Multivariate

TH2D * FigureK = nullptr;				//Figure of Merit for Kaon (Color Plot)
TH1D * HistogramKHalf = nullptr;			//Fitted Histogram when FOMKaon > 0.5
TH1D * HistogramKOne = nullptr;				//Fitted Histogram when FOMKaon > 1
TH1D * HistogramKThreeHalf = nullptr;			//Fitted Histogram when FOMKaon > 1.5

//TH1D * TwoDimensionHalf = nullptr;			//Not Needed
//TH1D * TwoDimensionOne = nullptr;			//Not Needed
//TH1D * TwoDimensionThreeHalf = nullptr;		//Not Needed

TH1D * FOMKaon = nullptr;				//Graph of Combined Figure of Merit 

TFile * File = nullptr;	
TCanvas * c1 = nullptr;

const int n = 100;

std::array<double, n> y{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
std::array<double, n> x{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


void OneD_MV_EB_V2::Begin(TTree * /*tree*/)
{

   TString option = GetOption();
}

void OneD_MV_EB_V2::SlaveBegin(TTree * /*tree*/)
{
 
   TString option = GetOption();

	//DEFINING HISTOGRAMS//

    HistogramKHalf = new TH1D("Figures of Merit", "Mass of Xic0 - FOM Kaon > 2.0", 100, 2370, 2570);
    HistogramKHalf->GetXaxis()->SetTitle("MeV");
    HistogramKHalf->GetYaxis()->SetTitle("Events Per 2 MeV");


    FigureK = new TH2D("Figures of Merit", "Color PLot of Xic0 Mass - One Dimensional Projections", 50, 0.7, 4.2, 50, 0.25, 1.0);
    FigureK->GetXaxis()->SetTitle("Log(PromptK_IPCHI2_OWNPV)");
    FigureK->GetYaxis()->SetTitle("PromptK_MC15TuneV1_ProbNNk");
    FigureK->GetZaxis()->SetTitle("Signal*Signal / Background*Background");

    FOMKaon = new TH1D("Figures of Merit", "Frequency of Kaon S:B FOMs", 100, 0, 2);
    FOMKaon->GetXaxis()->SetTitle("FOM");
    FOMKaon->GetYaxis()->SetTitle("Events Per 0.2 S:B");

    File = new TFile("OneD_MV_EB.root", "RECREATE");
    gFile = File;

    c1 = new TCanvas("Cavnas", "Test Canvas");

	//FOM CALCULATION//

    for (double i = 0; i < 50; i++){ 												//50 Boxes for the x-axis
        for (double j = 0; j < 50; j++){ 											//50 Boxes for the y-axis

            double x = 0.735 + (0.07 * i); 											//Formula for Find Midpoint of Each Box in the X
            double y = 0.2475 + (0.015 * j); 											//Formula for Midpoint of Each Box in the Y
	    double SignalK = ((131.946 + TMath::Exp(-1.631 + (25.157*x)) * (-3.83269 + TMath::Exp(7.66732 -1.15853 * x) + -3.83269 + TMath::Exp(3.15814 - 1.15853 * x))));  
	    //double SignalK = (199.86 + TMath::Exp(10.47 - (1.68 * x))) * (131.94 + TMath::Exp(-16.29 + (25.16 * y))); 		//OneD Probability Fomula for Signal Regions in IP_CHI and ProbNN
	    //double SignalK = ((-6889 + 21170 *x + 22.22*x*x + 24017*x*x*x -164000*x*x*x*x -3199*x*x*x*x*x + 270800*x*x*x*x*x*x + 274500*x*x*x*x*x*x*x - 230200*x*x*x*x*x*x*x*x - 674300*x*x*x*x*x*x*x*x*x + 523700*x*x*x*x*x*x*x*x*x*x) * (3650.80 - 4962.06*x + 2313.3 *x*x -177.6*x*x*x -114.541*x*x*x*x - 0.203669*x*x*x*x*x + 6.7287*x*x*x*x*x*x + 1.20619*x*x*x*x*x*x*x - 0.247072*x*x*x*x*x*x*x*x - 0.138001*x*x*x*x*x*x*x*x*x + 0.00240076*x*x*x*x*x*x*x*x*x*x));
           double BackgroundK = (111.07 + TMath::Exp(10.537 - (2.843 * x))) * (708.66 + TMath::Exp(-8.68 + (16.93 * y))); 	//OneD Probability Formula for Background Regios in IP_CHI and ProbNN
            fomK[i][j] = (SignalK / BackgroundK);}} 										//New Figure of Merit Produced by Dividing Signal by Background Formulas

}

Bool_t OneD_MV_EB_V2::Process(Long64_t entry)
{
   GetEntry(entry);
   fReader.SetLocalEntry(entry);

	//ADDITIONAL CUTS TO ENHANCE SIGNAL//

    double CorrectedOmegaMass = (*Omega_MM) - (*Lambda_MM) + 1115.683;

    bool BorderCut = (
          (TMath::Log10(*PromptK_IPCHI2_OWNPV) > 0.7)
        &&(TMath::Log10(*PromptK_IPCHI2_OWNPV) < 4.2) 
        &&(*PromptK_MC15TuneV1_ProbNNk > 0.25)
    );

    bool GeneralCuts = (
	(CorrectedOmegaMass > 1665 && CorrectedOmegaMass < 1680)
        &&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
        &&(*Xi_c0_PT > 1500)
    );
											//Right now we have a soup of events in the Multivariate Plot with no way of knowing which event belongs to each bin
											//These next lines allow us to find the FoM for each event and allow us to add the event back into the proper histogram

int p = floor(abs(TMath::Log10(*PromptK_IPCHI2_OWNPV) - 0.7)/(0.07));			//Allows us to get the value of variable IP_CHI to a specific bin
int q = floor(abs(*PromptK_MC15TuneV1_ProbNNk - 0.25)/(0.015));				//Allows us to get the value of variable ProbNN to a specific bin

double FOMK = fomK[p][q];								//So instead of the figure of merit iterating over midpoints, it now iterates over bin values

if (FOMK > 2 && GeneralCuts && BorderCut){						//If the bin passes these FoM values they will be added to a new histogram
    HistogramKHalf->Fill(*Xi_c0_MM);}	

    return kTRUE;
}

void OneD_MV_EB_V2::SlaveTerminate()
{

}

void OneD_MV_EB_V2::Terminate()
{
	TPad *pad1 = new TPad("pad1", "pad1", 0, 0.33, 1, 1);
	TPad *pad2 = new TPad("pad2", "pad2", 0, 0, 1, 0.33);
	pad2->SetTopMargin(0.030303);
	pad1->Draw();
	pad2->Draw();

    for (double i = 0; i < 50; i++){
        for (double j = 0; j < 50; j++){

            double x = 0.735 + (0.07 *i);
            double y = 0.2575 + (0.015 * j);

            FOMKaon->Fill(fomK[i][j]);							//Fills Histogram with each value of the Figure of Merit
            FigureK->Fill(x, y, fomK[i][j]);}}						//Fills a Color plot with each combination of x and y, and the corresponding FoM on the z-axis


    TF1 *myXifit = new TF1("myXifit", CrystalBall, 2370., 2570., 5);
   
    myXifit->SetParameter(0, 13750.0);			//# of signal events
    myXifit->SetParameter(1, 2471);			//mean value
    myXifit->SetParameter(2, 16);			//rms width of signal
    myXifit->SetParLimits(2, 0., 20.);		
    myXifit->SetParameter(3, 10.);			//sigma of Gaussian
    myXifit->SetParameter(4, .4);			//fraction in Gaussian
    myXifit->SetParLimits(4, 0.4, 0.99999);
    myXifit->SetParameter(5, 950);			//Intercept of Linear Bkgd
    myXifit->SetParameter(6, 0.0);			//Slope of Linear Bkgd
    myXifit->SetParLimits(6, 0.0, 0.001);
    myXifit->SetParameter(7, 0);			//Alpha
    myXifit->SetParLimits(7, 0.0, 5.0);
    myXifit->SetParameter(8, 0);			//n
    myXifit->SetParLimits(8, 0, 5);


    pad1->cd();
    HistogramKHalf->Fit("myXifit");
    HistogramKHalf->SetMinimum(0);


	int BinHeight1[100];
	double Pullx[100];
	int FitHeight1[100];
	double Pull1[100];

	double count1 = 0;

	for (int bin = 0; bin < 100; bin++){
		BinHeight1[bin] = HistogramKHalf->GetBinContent(bin + 1);
		Pullx[bin] = (bin + 1);
		int xvalue = 2370 + 2*(bin);
		FitHeight1[bin] = round(myXifit->Eval(xvalue));
		Pull1[bin] = (BinHeight1[bin] - FitHeight1[bin])/(TMath::Sqrt(FitHeight1[bin]));

	pad2->cd();
	TGraph* PullPlot = new TGraphErrors(100, Pullx, Pull1, x.data(), y.data());
	PullPlot->GetXaxis()->SetLimits(0.5,100.5);
	PullPlot->GetXaxis()->SetTickLength(0.);
	PullPlot->GetYaxis()->SetTickLength(0.);
	PullPlot->SetFillColor(38);
	PullPlot->GetYaxis()->SetTitle("Pull");
	PullPlot->GetYaxis()->CenterTitle();
	PullPlot->GetYaxis()->SetTitleSize(0.10);
	PullPlot->GetYaxis()->SetTitleOffset(0.2);
	PullPlot->GetXaxis()->SetLabelSize(0);
	PullPlot->GetYaxis()->SetLabelFont(42);
	PullPlot->GetYaxis()->SetLabelSize(0.06);
	PullPlot->SetTitle("");
	PullPlot->SetMinimum(-5);
	PullPlot->SetMaximum(5);
	PullPlot->SetMarkerStyle(20);
	PullPlot->Draw("AP");

	c1->Write("PullPlot");
    File->Close();

}}
