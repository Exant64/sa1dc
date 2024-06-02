#include <task.h>
#include <Ninja.h>


typedef struct sp_info {
	NJS_TEXLIST* texlist;
	NJS_TEXANIM* texanim;
	Sint32 animnum;
	Sint32 srcblend;
	Sint32 dstblend;
} sp_info;

struct sp_task;
typedef struct sp_link {
	struct sp_link* next;
	struct sp_task* head;
	void(*exec)(struct sp_link*);
	Uint32 numtask;
	sp_info* info;
	Uint32 sysflag;
	void* work;
} sp_link;

typedef struct particle_entry {
	sp_info* info;
	Uint32 wksize;
	void(*exec)(sp_link*);
	sp_link* link;
} particle_entry;

typedef struct particle_info {
	Float scl;
	Float sclspd;
	Float animspd;
	Float friction;
	Float yacc;
	NJS_POINT3 pos;
	NJS_POINT3 velo;
	NJS_ARGB argb;
} particle_info;

void EntryParticle(particle_entry** plistlist)
{
	while (*plistlist)
	{
		particle_entry* entry = *plistlist;

		sp_link* link = SpCreateLinkW(entry->info, entry->wksize);
		entry->link = link;

		if (entry->exec)
			entry->exec(link);

		++plistlist;
	}
}

INLINE_ASM(_SetParticle, "asm/nonmatching/./particle/_SetParticle.src");

INLINE_ASM(_func_8C0A3DAA, "asm/nonmatching/./particle/_func_8C0A3DAA.src");

INLINE_ASM(_func_8C0A3DC8, "asm/nonmatching/./particle/_func_8C0A3DC8.src");

INLINE_ASM(_func_8C0A3DD4, "asm/nonmatching/./particle/_func_8C0A3DD4.src");

