#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "License").
# You may not use this file except in compliance with the License.
#
# You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
# or http://www.illumos.org/license/CDDL.
# See the License for the specific language governing permissions
# and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file at usr/src/OPENSOLARIS.LICENSE.
# If applicable, add the following below this CDDL HEADER, with the
# fields enclosed by brackets "[]" replaced with your own identifying
# information: Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#
# Copyright (c) 2013-2016, Aurelien Larcher. All rights reserved.
#
include ../../make-rules/shared-macros.mk

COMPONENT_NAME=		openjpeg
COMPONENT_VERSION=	2.1.2
COMPONENT_FMRI=     	image/library/openjpeg
COMPONENT_CLASSIFICATION=System/Libraries
COMPONENT_SRC=		$(COMPONENT_NAME)-$(COMPONENT_VERSION)
COMPONENT_PROJECT_URL=	http://www.openjpeg.org/
COMPONENT_ARCHIVE=	$(COMPONENT_SRC).tar.gz
COMPONENT_ARCHIVE_HASH=	\
	sha256:4ce77b6ef538ef090d9bde1d5eeff8b3069ab56c4906f083475517c2c023dfa7
COMPONENT_ARCHIVE_URL=	https://github.com/uclouvain/openjpeg/archive/v$(COMPONENT_VERSION).tar.gz
COMPONENT_LICENSE=      BSD
COMPONENT_LICENSE_FILE= $(COMPONENT_NAME).license
COMPONENT_SUMMARY=      OpenJPEG library : Open source JPEG 2000 codecs

include $(WS_MAKE_RULES)/prep.mk
include $(WS_MAKE_RULES)/cmake.mk
include $(WS_MAKE_RULES)/ips.mk

CFLAGS+= -std=c99 -D_XOPEN_SOURCE=600
CFLAGS+= $(CPP_LARGEFILES)

#COMPONENT_PRE_CMAKE_ACTION =        ($(CLONEY) $(SOURCE_DIR) $(@D))

CMAKE_OPTIONS+= -DCMAKE_EXE_LINKER_FLAGS:STRING="-lnsl -lsocket"
# Openjpeg does not use CMake's internal variables.
CMAKE_OPTIONS+=	-DOPENJPEG_INSTALL_BIN_DIR=$(CMAKE_BINDIR.$(BITS))
CMAKE_OPTIONS+=	-DOPENJPEG_INSTALL_LIB_DIR=$(CMAKE_LIBDIR.$(BITS))
# For jar files
CMAKE_OPTIONS+=	-DOPENJPEG_INSTALL_SHARE_DIR=$(USRSHAREDIR)/lib/java
CMAKE_OPTIONS+= -DBUILD_CODEC:BOOL=ON
CMAKE_OPTIONS+= -DBUILD_DOC:BOOL=OFF
CMAKE_OPTIONS+= -DBUILD_JPIP:BOOL=ON
CMAKE_OPTIONS+= -DBUILD_JPWL:BOOL=ON
CMAKE_OPTIONS+= -DBUILD_MJ2:BOOL=ON
CMAKE_OPTIONS+= -DBUILD_PKGCONFIG_FILES:BOOL=ON
CMAKE_OPTIONS+= -DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_OPTIONS+= -DBUILD_TESTING:BOOL=OFF
CMAKE_OPTIONS+= -DBUILD_THIRDPARTY:BOOL=ON   

build: $(BUILD_32_and_64)

install: $(INSTALL_32_and_64)

test: $(NO_TESTS)

REQUIRED_PACKAGES += system/library
REQUIRED_PACKAGES += system/library/math
