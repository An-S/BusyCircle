#define compiler flags for cc65 as well as gcc
cc65flags = -c -O -l $(basename $<).lst $(addprefix -I, $(cbmincdirs)) $(addprefix -Wa-I, $(cbmincdirs))
ccflags = -c -O -Wa --std=gnu11 -fplan9-extensions
ld65flags = -Ln $(cbmdir)/src/$(exebasename).lbl -m $(cbmdir)/src/$(exebasename).map

exebasename = busycirle

#define basedirs for sources
cbmdir = ./cbm
linuxdir = ./linux
windir = ./win
sharedir = ./share

#get lists of source and header files for all targets
cbmtargets = $(wildcard $(cbmdir)/src/*.c)
linuxtargets = $(wildcard $(linuxdir)/src/*.c)
sharetargets = $(wildcard $(sharedir)/src/*.c)
cbmheads = $(wildcard $(cbmdir)/include/*.h)
linuxheads = $(wildcard $(linuxdir)/include/*.h)
shareheads = $(wildcard $(sharedir)/include/*.h)

#get object file names from source file names
cbmobjs = $(patsubst $(cbmdir)/src/%.c, $(cbmdir)/obj/%.o, $(cbmtargets))
linuxobjs = $(patsubst $(linuxdir)/src/%.c, $(linuxdir)/obj/%.o, $(linuxtargets))
shareobjs = $(patsubst $(sharedir)/src/%.c, $(sharedir)/obj/%.o, $(sharetargets))

cbmincdirs = $(cbmdir)/include $(sharedir)/include

#define directories with test code
cc65test = ./cbm/src/tests/*.o

#autorules to compile sources to objects for each target
$(cbmdir)/obj/%.o: $(cbmdir)/src/%.c	
	cl65 $(cc65flags) -o $@ $<

$(linuxdir)/obj/%.o: $(linuxdir)/src/%.c	
	gcc $(ccflags) -o $@ $<

$(sharedir)/obj/%.o: $(sharedir)/src/%.c	
	gcc $(ccflags) -o $@ $<

#define targets and their respective dependencies on header files
cbm: $(cbmobjs) $(cbmheads) $(shareheads)
	cl65 $(ld65flags) -o $(exebasename).prg 

linux: $(linuxobjs) $(linuxheads) $(shareheads)

share: $(shareobjs) $(shareheads)

#target to cleanup objects and other files
	.PHONY	clean
clean: 
	rm $(linuxobjs) $(cbmobjs) $(shareobjs)

#batch build targets
all:	cbm linux share
	echo $(cbmtargets), $(cbmobjs)
	echo $(linuxtargets), $(linuxobjs)
	echo $(sharetargets), $(shareobjs)

#for eventual usage of makedepend
# DO NOT DELETE
