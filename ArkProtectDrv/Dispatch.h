#ifndef CXX_Dispatch_H
#define CXX_Dispatch_H

#include <ntifs.h>
#include "ProcessCore.h"
#include "ProcessModule.h"
#include "ProcessThread.h"
#include "ProcessHandle.h"
#include "ProcessWindow.h"
#include "ProcessMemory.h"
#include "DriverCore.h"


// Method_Neither
/*
#define CTL_CODE( DeviceType, Function, Method, Access ) (                 \
((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method) \
*/

#define FILE_DEVICE_ARKPROTECT           0x8005

#define IOCTL_ARKPROTECT_PROCESSNUM        (UINT32)CTL_CODE(FILE_DEVICE_ARKPROTECT, 0x801, METHOD_NEITHER, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ARKPROTECT_ENUMPROCESS       (UINT32)CTL_CODE(FILE_DEVICE_ARKPROTECT, 0x802, METHOD_NEITHER, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ARKPROTECT_ENUMPROCESSMODULE (UINT32)CTL_CODE(FILE_DEVICE_ARKPROTECT, 0x803, METHOD_NEITHER, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ARKPROTECT_ENUMPROCESSTHREAD (UINT32)CTL_CODE(FILE_DEVICE_ARKPROTECT, 0x804, METHOD_NEITHER, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ARKPROTECT_ENUMPROCESSHANDLE (UINT32)CTL_CODE(FILE_DEVICE_ARKPROTECT, 0x805, METHOD_NEITHER, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ARKPROTECT_ENUMPROCESSWINDOW (UINT32)CTL_CODE(FILE_DEVICE_ARKPROTECT, 0x806, METHOD_NEITHER, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ARKPROTECT_ENUMPROCESSMEMORY (UINT32)CTL_CODE(FILE_DEVICE_ARKPROTECT, 0x807, METHOD_NEITHER, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ARKPROTECT_ENUMDRIVER        (UINT32)CTL_CODE(FILE_DEVICE_ARKPROTECT, 0x808, METHOD_NEITHER, FILE_READ_ACCESS | FILE_WRITE_ACCESS)



NTSTATUS
APIoControlPassThrough(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);

#endif // !CXX_Dispatch_H