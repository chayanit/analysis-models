/*
 * Histograms.h
 *
 *  Created on: 16 апр. 2016 г.
 *      Author: rostyslav
 */

#ifndef ANALYSIS_MSSMHBB_SRC_HISTOGRAMS_H_
#define ANALYSIS_MSSMHBB_SRC_HISTOGRAMS_H_

#include <iostream>		// standard in/out
#include <memory> 		// for std::shared_ptr
#include <string>
#include <map>
#include "TMath.h"

#include "TH1.h"
#include "TH2.h"
#include "TEfficiency.h"

#include "stdlib.h"

	class Histograms {
	public:
		Histograms();
		virtual ~Histograms();

		void Make(const int &size = 100);

//        struct Systematics{
//			Systematics() : central(0), up(0), down (0) {};
//			Systematics(const TH1* centr, const TH1* upper, const TH1* lower) :
//        		central(centr),
//        		up(upper),
//        		down(lower) {};
//        	~Systematics(){
//        		delete central;
//        		delete up;
//        		delete down;
//        	};
//        	TH1* central;
//        	TH1* up;
//        	TH1* down;
//        };
//
//
//        std::map<std::string, Systematics > & getSystematics();
		std::map<std::string, TEfficiency* >& getEff();
		std::map<std::string, TH1 * >& getHisto();

	protected:
//		std::map<std::string, Systematics > syst_;
		std::map<std::string,TH1* > histo_;
		std::map<std::string,TEfficiency* > eff_;

	};

#endif /* ANALYSIS_MSSMHBB_SRC_HISTOGRAMS_H_ */
