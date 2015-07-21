/*
 * Copyright (c) 2003, 2011, Oracle and/or its affiliates. All rights reserved.
 *
 * U.S. Government Rights - Commercial software. Government users are subject
 * to the Sun Microsystems, Inc. standard license agreement and applicable
 * provisions of the FAR and its supplements.
 *
 *
 * This distribution may include materials developed by third parties. Sun,
 * Sun Microsystems, the Sun logo and Solaris are trademarks or registered
 * trademarks of Sun Microsystems, Inc. in the U.S. and other countries.
 *
 */
#pragma ident   "@(#)entLPMappingTable.h 1.1     03/02/24 SMI"
/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.iterate.conf,v 5.4 2002/09/11 22:42:04 hardaker Exp $
 */
#ifndef ENTLPMAPPINGTABLE_H
#define ENTLPMAPPINGTABLE_H

/*
 * function declarations 
 */
void            init_entLPMappingTable(void);
void            initialize_table_entLPMappingTable(void);
Netsnmp_Node_Handler entLPMappingTable_handler;

Netsnmp_First_Data_Point entLPMappingTable_get_first_data_point;
Netsnmp_Next_Data_Point entLPMappingTable_get_next_data_point;

/*
 * column number definitions for table entLPMappingTable 
 */
#define COLUMN_ENTLPPHYSICALINDEX		1

typedef struct entLPMappingTableEntry_s {
        int_l entLogicalIndex;
        int_l *physicalIndexes;      /* array of Physical Table indexes */
        struct entLPMappingTableEntry_s *pNextLPMappingTableEntry;
} entLPMappingTableEntry_t;

extern int addLPMappingTableEntry(int xentLogicalIndex, int xentPhysicalIndex);

/*
  This function deletes the table entries for a given logical index
  and physical index. 

  Returns 1 for success and -1 for failure.
*/

extern int deleteLPMappingTableEntry(int xLogicalIndex, int xPhysicalIndex);
extern int deleteLPMappingLogicalIndex(int xentLogicalIndex);
extern int deleteLPMappingPhysicalIndex(int xentPhysicalIndex);


#endif                          /* ENTLPMAPPINGTABLE_H */
