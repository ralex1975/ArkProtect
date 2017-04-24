#ifndef CXX_DriverCore_H
#define CXX_DriverCore_H

#include <ntifs.h>
#include "Private.h"
#include "Imports.h"
#include "NtStructs.h"
#include "ProcessCore.h"


typedef struct _DRIVER_ENTRY_INFORMATION
{
	UINT_PTR  BaseAddress;
	UINT_PTR  Size;
	UINT_PTR  DriverObject;
	UINT_PTR  DirverStartAddress;
	UINT_PTR  LoadOrder;
	WCHAR     wzDriverName[100];
	WCHAR     wzDriverPath[MAX_PATH];
	WCHAR     wzServiceName[MAX_PATH];
	WCHAR     wzCompanyName[MAX_PATH];
} DRIVER_ENTRY_INFORMATION, *PDRIVER_ENTRY_INFORMATION;

typedef struct _DRIVER_INFORMATION
{
	UINT32                          NumberOfDrivers;
	DRIVER_ENTRY_INFORMATION        DriverEntry[1];
} DRIVER_INFORMATION, *PDRIVER_INFORMATION;


NTSTATUS
APEnumDriverModuleByLdrDataTableEntry(IN PLDR_DATA_TABLE_ENTRY PsLoadedModuleList, OUT PDRIVER_INFORMATION di, IN UINT32 DriverCount);

BOOLEAN 
APIsDriverInList(IN PDRIVER_INFORMATION di, IN PDRIVER_OBJECT DriverObject, IN UINT32 DriverCount);

VOID 
APInsertDriverToList(OUT PDRIVER_INFORMATION di, IN PDRIVER_OBJECT DriverObject, IN UINT32 DriverCount);

VOID
APEnumDriverModuleByTravelDirectoryObject(OUT PDRIVER_INFORMATION di, IN UINT32 DriverCount);

NTSTATUS
APEnumDriverInfo(OUT PVOID OutputBuffer, IN UINT32 OutputLength);

#endif // !CXX_DriverCore_H


