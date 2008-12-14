/**
 * $Id:
 *
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * The Original Code is Copyright (C) 2008 Blender Foundation.
 * All rights reserved.
 *
 * 
 * Contributor(s): Blender Foundation
 *
 * ***** END GPL LICENSE BLOCK *****
 */

#ifndef ED_OUTLINER_INTERN_H
#define ED_OUTLINER_INTERN_H

/* internal exports only */

struct wmWindowManager;

struct TreeStoreElem;

typedef struct TreeElement {
	struct TreeElement *next, *prev, *parent;
	ListBase subtree;
	float xs, ys;		// do selection
	int store_index;	// offset in tree store
	short flag, index;	// flag for non-saved stuff, index for data arrays
	short idcode;		// from TreeStore id
	short xend;			// width of item display, for select
	char *name;
	void *directdata;	// Armature Bones, Base, Sequence, Strip...
}  TreeElement;

/* TreeElement->flag */
#define TE_ACTIVE	1
#define TE_ICONROW	2

/* TreeStoreElem types */
#define TSE_NLA				1
#define TSE_NLA_ACTION		2
#define TSE_DEFGROUP_BASE	3
#define TSE_DEFGROUP		4
#define TSE_BONE			5
#define TSE_EBONE			6
#define TSE_CONSTRAINT_BASE	7
#define TSE_CONSTRAINT		8
#define TSE_MODIFIER_BASE	9
#define TSE_MODIFIER		10
#define TSE_LINKED_OB		11
#define TSE_SCRIPT_BASE		12
#define TSE_POSE_BASE		13
#define TSE_POSE_CHANNEL	14
/*#ifdef WITH_VERSE*/
#define TSE_VERSE_SESSION	15
#define TSE_VERSE_OBJ_NODE	16
#define TSE_VERSE_GEOM_NODE	17
/*#endif*/
#define TSE_PROXY			18
#define TSE_R_LAYER_BASE	19
#define TSE_R_LAYER			20
#define TSE_R_PASS			21
#define TSE_LINKED_MAT		22
/* NOTE, is used for light group */
#define TSE_LINKED_LAMP		23
#define TSE_POSEGRP_BASE	24
#define TSE_POSEGRP			25
#define TSE_SEQUENCE	26
#define TSE_SEQ_STRIP	27
#define TSE_SEQUENCE_DUP 28

/* outliner search flags */
#define OL_FIND					0
#define OL_FIND_CASE			1
#define OL_FIND_COMPLETE		2
#define OL_FIND_COMPLETE_CASE	3

/* button events */
#define OL_NAMEBUTTON		1


/* outliner_ops.c */
void outliner_operatortypes(void);
void outliner_keymap(struct wmWindowManager *wm);

/* outliner_header.c */
void outliner_header_buttons(const bContext *C, ARegion *ar);


#endif /* ED_OUTLINER_INTERN_H */

