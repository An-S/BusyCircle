#define compiler flags for cc65 as well as gcc
cc65flags = -c -O -l $(basename $<).lst $(addprefix -I, $(cbmincdirs))\
			 $(addprefix -Wa -I, $(cbmincdirs)) -D CBM_TARGET
ccflags := -c -O --std=gnu11 -fplan9-extensions $(shell /usr/local/bin/sdl2-config --cflags)
ld65flags = -Ln $(cbmdir)/src/$(exebasename).lbl -m $(cbmdir)/src/$(exebasename).map
ldflags := $(shell /usr/local/bin/sdl2-config --libs)
exebasename = busycircle

#define basedirs for sources
cbmbasedir = /home/mc78/Coding_64
cbmdir = ./cbm
linuxdir = ./linux
windir = ./win
sharedir = ./share
testdir = ./tests
sdldir = /usr/include/SDL2
sdllibdir = /usr/lib/x86_64-linux-gnu/

#get lists of source and header files for all targets
cbmtargets = $(wildcard $(cbmdir)/src/*.c)
cbmtests = $(wildcard $(cbmdir)/testsrc/*.c)
linuxtargets = $(wildcard $(linuxdir)/src/*.c)
sharetargets = $(wildcard $(sharedir)/src/*.c)
sharetests = $(wildcard $(sharedir)/testsrc/*.c)
sdltargets = $(wildcard $(sharedir)/SDL/src/*.c)

cbmheads = $(wildcard $(cbmdir)/include/*.h)
linuxheads = $(wildcard $(linuxdir)/include/*.h)
shareheads = $(wildcard $(sharedir)/include/*.h)
sdlheads = $(wildcard $(sharedir)/SDL/include/*.h)

#get object file names from source file names
cbmobjs = $(patsubst $(cbmdir)/src/%.c, $(cbmdir)/obj/%.o, $(cbmtargets))\
	$(patsubst $(sharedir)/obj%, $(sharedir)/cbmobj%, $(shareobjs))
cbmtestprgs = $(patsubst $(cbmdir)/testsrc/%.c, $(testdir)/cbm/%.prg, $(cbmtests))\
				$(patsubst $(sharedir)/testsrc/%.c, $(testdir)/cbm/%.prg, $(sharetests))

linuxobjs = $(patsubst $(linuxdir)/src/%.c, $(linuxdir)/obj/%.o, $(linuxtargets))
shareobjs = $(patsubst $(sharedir)/src/%.c, $(sharedir)/obj/%.o, $(sharetargets))
sharetestobjs = $(patsubst $(sharedir)/testsrc/%.c, $(sharedir)/testobj/%.o, $(sharetargets))
sdlobjs = $(patsubst $(sharedir)/SDL/src/%.c, $(sharedir)/SDL/obj/%.o, $(sdltargets))

shareincdirs = ../MCLib
cbmincdirs = $(cbmbasedir)/include $(cbmdir)/include $(sharedir)/include $(shareincdirs)
linuxincdirs = $(linuxdir)/include $(sharedir)/include $(sharedir)/SDL/include \
				$(shareincdirs) $(sdldir)

#define directories with test code
cc65test = ./cbm/src/tests/*.o

#autorules to compile sources to objects for each target
$(cbmdir)/obj/%.o: $(cbmdir)/src/%.c
	cl65 $(cc65flags) -o $@ $<

$(testdir)/cbm/%.prg: $(cbmdir)/testsrc/%.c
	-cl65 $(subst -c, ,$(cc65flags)) $(cbmobjs) -o $@ $<

$(sharedir)/cbmobj/%.o: $(sharedir)/src/%.c
	cl65 $(cc65flags) -o $@ $<

$(testdir)/cbm/%.prg: $(sharedir)/testsrc/%.c
	-cl65 $(subst -c, ,$(cc65flags)) $(cbmobjs) -o $@ $<


$(linuxdir)/obj/%.o: $(linuxdir)/src/%.c
	gcc $(ccflags) -D LINUX_TARGET $(addprefix -I, $(linuxincdirs)) -o $@ $<

$(sharedir)/obj/%.o: $(sharedir)/src/%.c
	gcc $(ccflags) -D LINUX_TARGET $(addprefix -I, $(linuxincdirs)) -o $@ $<

$(sharedir)/SDL/obj/%.o: $(sharedir)/SDL/src/%.c
	gcc $(ccflags) -D LINUX_TARGET $(addprefix -I, $(linuxincdirs)) -o $@ $<


#define targets and their respective dependencies on header files
share: $(shareobjs) $(shareheads)

cbm: $(cbmobjs) $(cbmheads) $(shareheads)
	cl65 $(ld65flags) -o $(exebasename).prg $(cbmobjs)

cbmtests: cbm $(cbmtestprgs)

linux: share $(linuxobjs) $(sdlobjs) $(linuxheads) $(sdlheads)
	echo ldflags: $(ldflags)
	gcc -o $(exebasename)_lnx $(linuxobjs) $(shareobjs) $(sdlobjs) $(ldflags) -lSDL2_ttf


editcbm:
	.PHONY editcbm

	gedit $(cbmtargets) $(cbmheads) $(sharetargets) $(shareheads) Makefile &

	.PHONY editlinux
editlinux:
	gedit $(linuxtargets) $(linuxheads) $(sharetargets) $(shareheads) $(sdltargets) $(sdlheads) Makefile &

	.PHONY editwin
editwin:
	gedit $(wintargets) $(winheads) $(sharetargets) $(shareheads) $(sdltargets) $(sdlheads) Makefile &





#target to cleanup objects and other files
	.PHONY clean
clean:
	-rm -fr "*.o" $(linuxobjs) $(cbmobjs) $(shareobjs) $(sdlobjs)

#batch build targets
all:	cbm linux share
	echo $(cbmtargets), $(cbmobjs)
	echo $(linuxtargets), $(linuxobjs)
	echo $(sharetargets), $(shareobjs)

#for eventual usage of makedepend
# DO NOT DELETE
