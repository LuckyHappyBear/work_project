local_dir := $(PWD)/sharedLib
local_src := $(wildcard $(local_dir)/*.c)
objs := $(subst .c,.o,$(local_src))
sharedLib_target := $(local_dir)/libshared_test.so

$(sharedLib_target): $(objs)
	$(CC) -shared $^ -o $@

%.o: %.c
	$(CC) -fPIC -o $@ -c $< $(CFLAGS)
