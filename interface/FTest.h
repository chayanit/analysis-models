/*
 * FTest.h
 *
 *  Created on: 12 Apr 2017
 *      Author: shevchen
 */

#ifndef Analysis_BackgroundModel_FTest_h_
#define Analysis_BackgroundModel_FTest_h_

/*
 * @author shevchen
 *
 * 12 Apr 2017
 */

#include <string>
#include <exception>
//#include <stringstream>
#include <boost/algorithm/string/join.hpp>

#include "Math/ProbFuncMathCore.h"
#include "TLatex.h"
#include "TAxis.h"

#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooAbsPdf.h"
#include "RooWorkspace.h"
#include "RooPlot.h"

#include "Analysis/BackgroundModel/interface/utilLib.h"
#include "Analysis/BackgroundModel/interface/RooSuperNovosibirsk.h"
#include "Analysis/BackgroundModel/interface/RooFitUtils.h"
#include "Analysis/BackgroundModel/interface/RooFitQuality.h"

namespace analysis{
namespace backgroundmodel{
class FTest {
public:
//	FTest() : pdf_family_(""), max_degree_(0), workspace_("workspace") {}  = default;
	FTest()  = default;
	virtual ~FTest() = default;
	FTest(const std::string& pdf_family) : pdf_family_(pdf_family) {};
	FTest(TH1 & data_obs, RooRealVar & observable, const std::string& pdf_family);
	FTest(RooDataSet & data_obs, RooRealVar & observable, const std::string& pdf_family);
	FTest(TH1 & data_obs, const double& xmin, const double& xmax, const std::string& pdf_family);
	FTest(RooDataSet & data_obs, const double& xmin, const double& xmax, const std::string& pdf_family);

	void PerformFTest(const int& max_degree, const std::string& output_folder, const int& min_degree = 0);
	std::string DefineSubrange();

//	void Initialise();

	void CheckPdfFamily();
	void GetPdf(const int& degree, const std::string& name);

private:

	void PrintRooFitResults(RooFitResult& r);
	Chi2Ndf PlotFitResult(const std::string& pdf_name, const std::string& output);
	double CalculateChi2();
	void AdjustPDFVars(const int& relative_index = 0);

	std::string pdf_family_;
	std::string obs_name_;
	std::string data_name_;
	RooWorkspace workspace_;
	static const std::vector<std::string> availablePDFs_;
};
}
}
#endif /* Analysis_BackgroundModel_FTest_h_ */
