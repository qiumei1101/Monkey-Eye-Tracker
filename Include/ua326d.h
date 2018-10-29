
//// ua326.h ////////////////////////////////

int _stdcall OpenUA326_a(int n, HANDLE &ftHandle);
int _stdcall OpenUA326_b(int n, HANDLE &ftHandle);
HANDLE _stdcall OpenUA326_a1(int n);
HANDLE _stdcall OpenUA326_b1(int n);
int _stdcall CloseUA326_a(HANDLE ftHandle);
int _stdcall CloseUA326_b(HANDLE ftHandle);
int _stdcall outb(HANDLE ftHandle, UCHAR port ,UCHAR dat1);
BYTE _stdcall din(HANDLE ftHandle);
BYTE _stdcall vin(HANDLE ftHandle);
void _stdcall dout(HANDLE ftHandle,BYTE dd);
int _stdcall ss326(HANDLE ftHandle,short *addat,short fch,short chn,short gn);
int _stdcall mm326(HANDLE ftHandle,short *addat,short fch,short chn,long fr,long leg,short gn);
int _stdcall start326(HANDLE ftHandle,short fch,short chn,long fr,short gn);
int _stdcall read326(HANDLE ftHandle,short *addat,long leg);
int _stdcall get_status(HANDLE ftHandle,DWORD *RxBytes,DWORD *TxBytes);
int _stdcall stop326(HANDLE ftHandle);
void _stdcall daout(HANDLE ftHandle,short dan,short dat);
void _stdcall daout2(HANDLE ftHandle,short da1,short da2);
void _stdcall daout4(HANDLE ftHandle,short da1,short da2, short da3, short da4);
void _stdcall read_n(HANDLE ftHandle, long *rn);
void _stdcall reset_n(HANDLE ftHandle);
