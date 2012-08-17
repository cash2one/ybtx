ROOT_DIR:=../../..

include $(ROOT_DIR)/Makefile.include

FILE=$(wildcard *.cpp)

#LUAFILE=$(wildcard lua/*.c)
#LUATEMPOBJ=$(LUAFILE:%.c=%.o)
#LUAOBJ=$(subst lua/,,$(LUATEMPOBJ))	

LUAPROFILERFILE=$(wildcard luaprofiler/*.cpp)
LUAPROFILERTEMPOBJ=$(LUAPROFILERFILE:%.cpp=%.o)
LUAPROFILEROBJ=$(subst luaprofiler/,,$(LUAPROFILERTEMPOBJ))

MODULES:=$(FILE:%.cpp=%.o) $(LUAPROFILEROBJ) #$(LUAOBJ)
DEPEND_LIB=-Wl,-E -ldl -lreadline -lhistory -lncurses $(LIB_LUA)

INCLUDE:=-I$(ROOT_DIR)/$(ENGINE_DIR)/include -I$(ROOT_DIR)/$(ENGINE_DIR)/sdk/inc -I$(ROOT_DIR)/$(IMPLIB_DIR)/inc

TARGET_LIB:=$(ROOT_DIR)/$(BIN_DIR)/$(BUILD_FLAG)/libScript.so

#����ʹ�õ���lua5.14 + coco 1.16������coco��makefile���ã�����lua������O2ѡ����б��룬��Ϊcoco��64λ����Ǹ���O2ѡ��д��
#�ο�coco�Լ��ı���ѡ���������lua�ı���ѡ������
LUACC:=gcc -O2 -Wall -fpic -c 

all: $(TARGET_LIB)

$(TARGET_LIB) : $(DEPENDENCIES)
	@$(ECHO) $(STR_SHARED)
	@$(CC) $(CSHARED) $(TARGET_LIB) *.o -L$(ROOT_DIR)/$(BIN_DIR)/$(BUILD_FLAG) -L$(ROOT_DIR)/$(LIB_DIR)/$(BUILD_FLAG) $(DEPEND_LIB)


%.o:luaprofiler/%.cpp
	@$(ECHO) $(STR_COMPILE): $<
	@$(CC) $(CMODULE) $< $(INCLUDE)


%.d:luaprofiler/%.cpp
	@$(CC) -MM $(INCLUDE) $< > $@.tmp;\
	sed  's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@;\
	rm -f $@.tmp

ifneq ($(MAKECMDGOALS),clean)
include $(MODULES:.o=.d)
endif

clean:
	@$(ECHO) $(STR_CLEAN)
	@$(RM) -f *.o *.a *.d *.so
	@$(RM) -f $(TARGET_LIB)