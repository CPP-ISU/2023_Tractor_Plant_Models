/* Include files */

#include "untitled_cgxe.h"
#include "m_eYAQCCbuL5W8pVsD0Md0JB.h"
#include "m_vgpHAlo0eWgN3UpjRmEzkC.h"

unsigned int cgxe_untitled_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 108558256 &&
      ssGetChecksum1(S) == 2111005026 &&
      ssGetChecksum2(S) == 879949658 &&
      ssGetChecksum3(S) == 3176080848) {
    method_dispatcher_eYAQCCbuL5W8pVsD0Md0JB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2857985075 &&
      ssGetChecksum1(S) == 1614404834 &&
      ssGetChecksum2(S) == 3713768359 &&
      ssGetChecksum3(S) == 1109058707) {
    method_dispatcher_vgpHAlo0eWgN3UpjRmEzkC(S, method, data);
    return 1;
  }

  return 0;
}
