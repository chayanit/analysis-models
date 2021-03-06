/*
 * RooSuperNovosibirsk.h
 *
 *  Created on: 12 Apr 2017
 *      Author: shevchen
 */

#ifndef Analysis_Models_RooSuperNovosibirsk_h_
#define Analysis_Models_RooSuperNovosibirsk_h_

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooAbsReal.h"
#include "RooListProxy.h"
#include <string>
#include "TMath.h"

namespace analysis {
namespace models {

/*
 * @author shevchen
 *
 * 12 Apr 2017
 */
class RooSuperNovosibirsk: public RooAbsPdf {
public:
	inline RooSuperNovosibirsk() = default;
	RooSuperNovosibirsk(const char *name, const char *title,
            RooAbsReal& x,
            RooAbsReal& peak,
            RooAbsReal& width,
            RooAbsReal& tail,
			const RooArgList& coefList);
	RooSuperNovosibirsk(const RooSuperNovosibirsk& other, const char* name=0) ;
	virtual TObject* clone(const char* newname) const;
	inline virtual ~RooSuperNovosibirsk() = default;

protected:
	double evaluate() const;

    RooRealProxy x_ ;
    RooRealProxy peak_ ;
    RooRealProxy width_ ;
    RooRealProxy tail_ ;
    RooListProxy coefList_;

private:
    ClassDef(RooSuperNovosibirsk,1)
};

} /* namespace models */
} /* namespace analysis */

#endif /* Analysis_Models_RooSuperNovosibirsk_h_ */
