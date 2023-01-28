/* Include files */

#include "Test_Stand_Trans_Controller_cgxe.h"
#include "m_45waa4IAejLI27VsMyOdUF.h"
#include "m_vgpHAlo0eWgN3UpjRmEzkC.h"
#include "m_GacRQAA80wK47Fj0f9XGeC.h"

unsigned int cgxe_Test_Stand_Trans_Controller_method_dispatcher(SimStruct* S,
  int_T method, void* data)
{
  if (ssGetChecksum0(S) == 324892178 &&
      ssGetChecksum1(S) == 850170599 &&
      ssGetChecksum2(S) == 1304688015 &&
      ssGetChecksum3(S) == 917591521) {
    method_dispatcher_45waa4IAejLI27VsMyOdUF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2857985075 &&
      ssGetChecksum1(S) == 1614404834 &&
      ssGetChecksum2(S) == 3713768359 &&
      ssGetChecksum3(S) == 1109058707) {
    method_dispatcher_vgpHAlo0eWgN3UpjRmEzkC(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 4227751030 &&
      ssGetChecksum1(S) == 962950199 &&
      ssGetChecksum2(S) == 2547763219 &&
      ssGetChecksum3(S) == 2580542805) {
    method_dispatcher_GacRQAA80wK47Fj0f9XGeC(S, method, data);
    return 1;
  }

  return 0;
}
