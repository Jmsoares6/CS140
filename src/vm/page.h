#ifndef VM_PAGE_H_
#define VM_PAGE_H_
#include "lib/kernel/hash.h"
#include "filesys/off_t.h"
#include "lib/debug.h"

void suppl_pt_init (struct hash *suppl_pt);

/* Supplemental page table entry */
struct suppl_pte
{
  uint8_t *upage;                 /* Virtual address, used as hash key */
  struct file *file;              /* File this page is mapped to */
  off_t offset;                   /* Offset in the file this page is mapped to*/
  size_t bytes_read;              /* Number of bytes read from the file */
  struct hash_elem elem_hash;     /* Element for supplemental page table */
};


#endif /* vm/page.h */