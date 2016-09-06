// Copyright (c) 2016, Lawrence Livermore National Security, LLC. Produced
// at the Lawrence Livermore National Laboratory.  Written by Lee Busby,
// busby1@llnl.gov. LLNL-CODE-702338. All rights reserved.
// See ../../Copyright for additional notices.

#ifndef ir_special_h
#define ir_special_h

#ifdef irep_c
// This file is logically part of irep.c, which is the only file that
// should need to include it.  It contains definitions that come
// from client code, so is a separate file for convenience.

// =======================================================================
// Define callback functions.
// =======================================================================
static struct { const char *pat; int nprm; int nret; } cbf_tbl[] = {
  { "^table1.table3.f3$",          3, 1 },
  { "^table1.table2[?*].f2$",      3, 1 },
  { "^table1.f1$",                 3, 1 },
};


// =======================================================================
// Define special handling functions.
// =======================================================================

// Forward declarations for special handling functions:
static int ir_ignore(lua_State *L, sbuf_t *sb, char *fp, char *lp);

// -----------------------------------------------------------------------
// The special handling table itself:
static struct { const char *pat; sh_handler h; } sh_tbl[] = {
  { "^table1.table3.xx$",          ir_ignore },
};

// -----------------------------------------------------------------------
// Definitions for the special handling functions:

static int ir_ignore(lua_State *L, sbuf_t *sb, char *fp, char *lp) { return 0; }

#endif
#endif
