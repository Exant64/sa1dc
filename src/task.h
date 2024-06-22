#ifndef TASK_H

#include <ninja.h>

typedef struct Angle3
{
	Angle x, y, z;
} Angle3;

typedef struct taskwk {
	Sint8 mode;
	Sint8 smode;
	Uint8 id;
	Uint8 btimer;
	Sint16 flag;
	Uint16 wtimer;
	union
	{
		Uint8 b[4];
		Uint16 w[2];
		Uint32 l;
		Float f;
		Void* ptr;
	} counter;
	union
	{
		Sint8 b[4];
		Sint16 w[2];
		Sint32 l;
		Float f;
		Void* ptr;
	} timer, value;
	Angle3 ang;
	NJS_POINT3 pos;
	NJS_POINT3 scl;
	void* cwp;
	void* ewp;
} taskwk;

typedef struct task
{
	struct task* next;
	struct task* last;
	struct task* ptp;
	struct task* ctp;
	void(*exec)(struct task*);
	void(*disp)(struct task*);
	void(*dest)(struct task*);
	void* ocp;
	taskwk* twp;
	void* mwp;
	void* fwp;
	void* awp;
	void* thp;
} task;


#define TASK_H

#endif