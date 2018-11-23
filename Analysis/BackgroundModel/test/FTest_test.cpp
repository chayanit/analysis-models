/*
 * FTest_test.cpp
 *
 *  Created on: 12 Apr 2017
 *      Author: shevchen
 *
 *      Unity test of FTest class
 */

#include "Analysis/BackgroundModel/interface/FTest.h"

#include "TFile.h"
#include "TTree.h"

#include "RooDataSet.h"
#include "RooRealVar.h"
#include "Analysis/BackgroundModel/interface/utilLib.h"

using namespace analysis::backgroundmodel;
using namespace std;

struct sub_range{
	sub_range(const double& xmin, const double& xmax, const int& nbins, const string& pdf) :
		xmin(xmin), xmax(xmax), nbins(nbins), pdf(pdf) {};
	double xmin; double xmax;
	int nbins;
	std::string pdf;
};

int main(){
	TFile f("data/2016DataRereco_05_01_2017/TripleBTagReverseSelectionBtoH2016_prescale_13TeV_G4.root","READ");
	TTree& t = *GetFromTFile<TTree>(f,"MssmHbb_13TeV");
	string pdf = "superdijetlinearprod";//"supernovosibirsk";//"supernovoeffprod";//"superdijeteffprod";//"berneffprod";//
//	sub_range sr(200,650,45,pdf);
	sub_range sr(350,1190,42,pdf);
//	sub_range sr(500,1700,48,pdf);
	RooRealVar x("mbb","mbb",sr.xmin,sr.xmax,"GeV");
	x.setBins(sr.nbins);
	RooDataSet data("data","data",RooArgSet(x),RooFit::Import(t));
	data.Print();


	FTest test(data,x,pdf);
	string dir_path = "test/FTest/" + test.DefineSubrange() + "/" + pdf;
	CheckOutputDir(dir_path);
	test.PerformFTest(4,dir_path);

	return 0;
}
