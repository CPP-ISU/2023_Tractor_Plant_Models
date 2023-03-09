/* Include files */

#include "Throttle_dyno_cgxe.h"
#include "m_nV8sLrn9cmGORYLmX8ZATF.h"
#include "m_l28rcAnd6AG7UcNfftFmPG.h"

unsigned int cgxe_Throttle_dyno_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 1528384496 &&
      ssGetChecksum1(S) == 119869233 &&
      ssGetChecksum2(S) == 2115619988 &&
      ssGetChecksum3(S) == 2365411897) {
    method_dispatcher_nV8sLrn9cmGORYLmX8ZATF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2052526170 &&
      ssGetChecksum1(S) == 2090347311 &&
      ssGetChecksum2(S) == 1874688775 &&
      ssGetChecksum3(S) == 734216295) {
    method_dispatcher_l28rcAnd6AG7UcNfftFmPG(S, method, data);
    return 1;
  }

  return 0;
}
