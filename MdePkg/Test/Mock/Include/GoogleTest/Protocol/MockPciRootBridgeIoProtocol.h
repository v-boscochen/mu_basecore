/** @file
  This file declares a mock of PCI Root Bridge IO Protocol.

  Copyright (c) Microsoft Corporation.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef MOCK_PCIROOTBRIDGEIOPROTOCOL_H
#define MOCK_PCIROOTBRIDGEIOPROTOCOL_H

#include <Library/GoogleTestLib.h>
#include <Library/FunctionMockLib.h>

extern "C" {
  #include <Uefi.h>
  #include <Protocol/PciRootBridgeIo.h>
}

//
// Declarations to handle usage of the Pci Root Bridge Io Protocol by creating mock
//
struct MockPciRootBridgeIoConfigAccess {
  MOCK_INTERFACE_DECLARATION (MockPciRootBridgeIoConfigAccess);

  MOCK_FUNCTION_DECLARATION (
    EFI_STATUS,
    MockPciRootBridgeIoRead,
    (IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL              *This,
     IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH    Width,
     IN     UINT64                                   Address,
     IN     UINTN                                    Count,
     IN OUT VOID                                     *Buffer)
    );
  MOCK_FUNCTION_DECLARATION (
    EFI_STATUS,
    MockPciRootBridgeIoWrite,
    (IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL              *This,
     IN     EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH    Width,
     IN     UINT64                                   Address,
     IN     UINTN                                    Count,
     IN OUT VOID                                     *Buffer)
    );
};

MOCK_INTERFACE_DEFINITION (MockPciRootBridgeIoConfigAccess);
MOCK_FUNCTION_DEFINITION (MockPciRootBridgeIoConfigAccess, MockPciRootBridgeIoRead, 5, EFIAPI);
MOCK_FUNCTION_DEFINITION (MockPciRootBridgeIoConfigAccess, MockPciRootBridgeIoWrite, 5, EFIAPI);

EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  PCI_ROOT_BRIDGE_IO_PROTOCOL_MOCK = {
  NULL,                                                  // EFI_HANDLE                                         ParentHandle;
  NULL,                                                  // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM        PollMem;
  NULL,                                                  // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM        PollIo;
  { NULL,                    NULL                     }, // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS             Mem;
  { NULL,                    NULL                     }, // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS             Io;
  { MockPciRootBridgeIoRead, MockPciRootBridgeIoWrite }, // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS             Pci;
  NULL,                                                  // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_COPY_MEM           CopyMem;
  NULL,                                                  // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_MAP                Map;
  NULL,                                                  // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_UNMAP              Unmap;
  NULL,                                                  // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ALLOCATE_BUFFER    AllocateBuffer;
  NULL,                                                  // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FREE_BUFFER        FreeBuffer;
  NULL,                                                  // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FLUSH              Flush;
  NULL,                                                  // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GET_ATTRIBUTES     GetAttributes;
  NULL,                                                  // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_SET_ATTRIBUTES     SetAttributes;
  NULL,                                                  // EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_CONFIGURATION      Configuration;
};

extern "C" {
  extern EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *gPciRootBridgeIoProtocol = &PCI_ROOT_BRIDGE_IO_PROTOCOL_MOCK;
}

#endif // MOCK_PCIIOPROTOCOL_H
