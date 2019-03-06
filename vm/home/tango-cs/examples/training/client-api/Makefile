#=============================================================================
#
# file :        Makefile
#
# description : build exmple prgrames for tango training
#
#

#-----------------------------------------
#	Set default directories
#-----------------------------------------


DEBUG = -g


INCLUDE_DIRS =	 -I/usr/local
LIB_DIRS    =    -L /usr/local
TARGET = reading01 reading02 reading03 asynread01 asynread02 asynread03 asyncmd01 writing01 writing02 command01 event01 group01 pipe01 pipe02 tangotypes01 devvar01
#-----------------------------------------
#	Set  CXXFLAGS and LDFLAGS
#-----------------------------------------

LDFLAGS = $(LIB_DIRS) -ltango	\
-llog4tango \
-lomniORB4  \
-lomniDynamic4 \
-lomnithread \
-lCOS4 \
-lzmq


CXXFLAGS +=  -std=c++0x $(DEBUG) $(INCLUDE_DIRS)


#redeinfe suffix for buildin targe from single cpp source
.cpp:
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

all: $(TARGET)

clean:
	rm -f *.o  core* \
	$(TARGET)
