AC_PREREQ(2.59)
define([svnversion], esyscmd([sh -c "svnversion -n"]))
AC_INIT([OpenSMT 2.0.svnversion], [(unstable)], [antti.hyvarinen@gmail.com])
config_flags="$*"
AC_DEFINE_UNQUOTED([CONFIG_FLAGS], ["$config_flags"], [Flags passed to configure])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR(autotools)
AM_INIT_AUTOMAKE
AC_DISABLE_SHARED

AC_PROG_LIBTOOL
AC_PROG_CC
AC_PROG_CXX
AC_PROG_YACC
AM_PROG_LEX
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

LT_INIT

AC_DEFINE(SVN_REVISION, "svnversion", [SVN Revision])

AC_ARG_ENABLE(library,
  AC_HELP_STRING([--enable-library],
                 [produces OpenSMT libraries (default=no)]),
  want_library="yes",
  want_library="no")

AM_CONDITIONAL([WANT_LIBRARY], [test "$want_library" = "yes"])

#
# Statically linked version
#
#AC_ARG_ENABLE(staticlibs,
#  AC_HELP_STRING([--enable-staticlibs],
#                 [enable statically linked libraries (-static) @<:@yes@:>@)]),
#  [:],
#  [enable_staticlibs="no"])
#
#AM_CONDITIONAL([ENABLE_STATIC], [test "$enable_static" = "yes"])

#if test $enable_staticlibs = "yes" ; then
#  config_staticlibs="-static"
#else
#  config_static=""
#fi
#echo "Compile statically linked libraries... ${enable_staticlibs}"
#
#
# Profiling
#
AC_ARG_ENABLE(profiling,
  AC_HELP_STRING([--enable-profiling],
                 [enable profiling (-pg) @<:@no@:>@]),
  [:],
  enable_profiling="no")

if test $enable_profiling = "yes" ;
then
  config_profiling="-pg"
elif test $enable_profiling = "no" ;
then
  config_profiling=""
fi

AM_CONDITIONAL([ENABLE_PROFILING], [test "$enable_profiling" = "yes"])

echo "Compile with profiling... ${enable_profiling}"

#
# Optimization
#
AC_ARG_ENABLE(optimization,
  AC_HELP_STRING([--enable-optimization],
                 [enable optimization by compiler (-O3) @<:@yes@:>@]),
  [:],
  [enable_optimization="yes"])

if test $enable_optimization = "yes" ;
then
  config_optimization_compiler="-O3"
  config_optimization_preproc="-DOPTIMIZE -DNDEBUG"
else
  config_optimization_compiler="-O0"
  config_optimization_preproc=""
fi
AM_CONDITIONAL([ENABLE_OPTIMIZATION], [test "$enable_optimization" = "yes"])
echo "Setting preprocessor optimization flags to... ${config_optimization_preproc:-none}"
echo "Setting compiler optimization flags to...  ${config_optimization_compiler:-none}"
#
# Proof production
#
AC_ARG_ENABLE(proof,
  AC_HELP_STRING([--enable-proof],
                 [enable proof production @<:@no@:>@)]),
  [:],
  [enable_proof="no"])

if test $enable_proof = "yes" ;
then
  config_proof="-DPRODUCE_PROOF"
else
  config_proof=""
fi

AM_CONDITIONAL([ENABLE_PROOF], [test "$enable_proof" = "yes"])
echo "Produce proofs... ${enable_proof}"

#
# Enable Custom memory allocation for forbid lists
#
AC_ARG_ENABLE(custom_memalloc,
  AC_HELP_STRING([--enable-custom_memalloc],
                 [enable custom memory allocation for forbid lists@<:@yes@:>@]),
  [:],
  [enable_custom_memalloc="yes"])

if test $enable_custom_memalloc = "yes" ;
then
  config_custom_memalloc="-DCUSTOM_EL_ALLOC"
else
  config_custom_memalloc=""
fi
AM_CONDITIONAL([ENABLE_CUSTOMMEMALLOC], [test "$enable_custom_memalloc" = "yes"])
echo "Use custom memory allocation for forbid lists...  $enable_custom_memalloc"


#
# Enable Pedantic Assertion Checking
#
AC_ARG_ENABLE(pedantic,
  AC_HELP_STRING([--enable-pedantic],
                 [enable pedantic assertion checking @<:@no@:>@]),
  [:],
  [enable_pedantic="no"])

if test $enable_pedantic = "yes" ;
then
  config_pedantic_debug="-DPEDANTIC_DEBUG"
else
  config_pedantic_debug=""
fi
AM_CONDITIONAL([ENABLE_PEDANTIC], [test "$enable_pedantic" = "yes"])
echo "Do pedantic assertion checks... $enable_pedantic"

#
# Enable Stupid Theory Propagation
#
AC_ARG_ENABLE(clever_theoryprop,
  AC_HELP_STRING([--enable-clever_theoryprop],
                 [enable clever theorypropagation @<:@no@:>@]),
  [:],
  [enable_clever_theoryprop="no"])

if test $enable_clever_theoryprop = "no" ;
then
  config_stupid_theoryprop="-DIGNORE_DL_THEORYPROPAGATION"
else
  config_stupid_theoryprop=""
fi
AM_CONDITIONAL([ENABLE_STUPID_THEORYPROP], [test "$enable_clever_theoryprop" = "yes"])

echo "Propagate from theories with decision level...  ${enable_clever_theoryprop}"

#
# Store explanations in terms
#
AC_ARG_ENABLE(term_explanations,
  AC_HELP_STRING([--enable-term_explanations],
                 [store explanations in terms @<:@yes@:>@]),
  [:],
  [enable_term_explanations="yes"])

if test $enable_term_explanations = "yes" ;
then
  config_term_explanations="-DTERMS_HAVE_EXPLANATIONS"
else
  config_term_explanations=""
fi
AM_CONDITIONAL([ENABLE_TERM_EXPLANATIONS], [test "$enable_term_explanations" = "yes"])

echo "Store explanations in terms...  ${enable_term_explanations}"


#
# Enable the buggy implementation of the structure sharing
#
AC_ARG_ENABLE(sharebug,
  AC_HELP_STRING([--enable-sharebug],
                 [enable the structure sharing bug in propositional flattening @<:@no@:>@]),
  [:],
  [enable_sharebug="no"])

if test $enable_sharebug = "yes" ;
then
  config_sharebug="-DENABLE_SHARING_BUG"
else
  config_sharebug=""
fi
AM_CONDITIONAL([ENABLE_SHAREBUG], [test "$enable_sharebug" = "yes"])
echo "Enable sharing bug...  ${enable_sharebug} (${config_sharebug:-none})"

AC_ARG_ENABLE(congruencesubstitution,
  AC_HELP_STRING([--enable-congruencesubstitution],
                 [enable the top level substitutions using congruence
                  closure @<:@yes@:>@]),
  [:],
  [enable_congruencesubstitution="no"])

if test $enable_congruencesubstitution = "yes" ;
then
  config_congruencesubstitution="-DENABLE_CONGRUENCESUBSTITUTION"
else
  config_congruencesubstitution=""
fi
AM_CONDITIONAL([ENABLE_CONGRUENCESUBSTITUTION], [test "$enable_congruencesubstitution" = "yes"])
echo "Use congruence substitution...  ${enable_congruencesubstitution}"

AC_ARG_ENABLE(oldsubstitution,
  AC_HELP_STRING([--enable-oldsubstitution],
                 [enable old substitution @<:@yes@:>@]),
  [:],
  [enable_oldsubstitution="yes"])

if test $enable_oldsubstitution = "yes" ;
then
  config_oldsubstitution="-DOSMT1_SUBSTITUTION"
else
  config_oldsubstitution=""
fi
AM_CONDITIONAL([ENABLE_OLDSUBSTITUTION], [test "$enable_oldsubstitution" = "yes"])
echo "Use old substitution...  ${enable_oldsubstitution}"

#
#
# Enable simplification debug
#
AC_ARG_ENABLE(simplification_debug,
  AC_HELP_STRING([--enable-simplification_debug],
                 [enable simplification debug @<:@no@:>@)]),
  [:],
  enable_simplification_debug="no")

if test "${enable_simplification_debug}" = "yes";
then
  config_simplification_debug="-DSIMPLIFY_DEBUG"
else
  config_simplification_debug=""
fi
AM_CONDITIONAL([ENABLE_SIMPLIFICATION_DEBUG], [test "$enable_simplification_debug" = "yes"])
echo "Enable simplification debug...  ${enable_simplification_debug}"


#
# Enable GC debug
#
AC_ARG_ENABLE(gcdebug,
  AC_HELP_STRING([--enable-gcdebug],
                 [enable garbage collection debug @<:@no@:>@]),
  [:],
  [enable_gc_debug="no"])

if test $enable_gc_debug = "yes" ;
then
  config_gc_debug="-DGC_DEBUG"
else
  config_gc_debug=""
fi
AM_CONDITIONAL([ENABLE_GC_DEBUG], [test "$enable_gc_debug" = "yes"])
echo "Enable garbage collection debug... ${enable_gc_debug}"



#
# SMTCOMP version
#
AC_ARG_ENABLE(smtcomp,
  [AC_HELP_STRING([--enable-smtcomp],
                 [enable smtcomp mode @<:@no@:>@])],
  [:],
  [enable_smtcomp="no"])

if test $enable_smtcomp = "yes" ;
then
  config_smtcomp="-DSMTCOMP -march=opteron -static"
else
  config_smtcomp=""
fi
echo "Compile for smtcomp... ${enable_smtcomp}"

AM_CONDITIONAL([ENABLE_SMTCOMP], [test "$enable_smtcomp" = "yes"])

# Complain if smtcomp is enabled and optimization is disabled
if test $enable_smtcomp = "yes" -a $enable_optimization = "no" ;
then
  echo "Error: smtcomp requires optimizations"
  exit
fi

# Complain if smtcomp is enabled and proof is enabled
if test $enable_smtcomp = "yes" -a $enable_proof = "yes" ;
then
  echo "Error: cannot enable proof with smtcomp"
  exit
fi


# Complain if both pedantic debug and optimization are enabled
if test $enable_pedantic = "yes" -a $enable_optimization = "yes" ;
then
  echo "Error: cannot enable both pedantic debug and optimization"
  exit
fi

def_flags="$config_optimization $config_pedantic_debug $config_gc_debug $config_smtcomp $config_static $config_proof $config_stupid_theoryprop $config_sharebug $config_simplification_debug $config_optimization_preproc $config_congruencesubstitution $config_oldsubstitution $config_custom_memalloc $config_term_explanations"
comp_flags="-W -Wall -g -Wno-deprecated $config_profiling $config_optimization_compiler"

def_flags=`echo ${def_flags} |sed 's/ [ ]*/ /g'`
comp_flags=`echo ${comp_flags} |sed 's/ [ ]*/ /g'`

AM_CFLAGS=""
AM_CXXFLAGS=$AM_CFLAGS

CFLAGS=""
CXXFLAGS=""
CPPFLAGS=""

# Allow user to use a GMP lib in a non-standard location
AC_ARG_WITH([gmp],
	    [AS_HELP_STRING([--with-gmp=prefix],
			    [Use this when GMP is in a non-standard location (e.g /opt/local in MacPorts)])],
			    [NONSTDGMPPATH=1],
			    [NONSTDGMPPATH=0])
if test $NONSTDGMPPATH = 1 ; then
  AM_CXXFLAGS="$AM_CXXFLAGS -I$with_gmp/include"
  AM_LDFLAGS="$AM_LDFLAGS -L$with_gmp/lib"
fi

# Allow user to use a GMP lib in a non-standard location
AC_ARG_WITH([readline],
	    [AS_HELP_STRING([--with-readline=prefix],
			    [Use this when readline is in a non-standard location])],
			    [NONSTDREADLINEPATH=1],
			    [NONSTDREADLINEPATH=0])

if test $NONSTDREADLINEPATH = 1 ; then
  AM_CFLAGS="$AM_CFLAGS -I$with_readline/include"
  AM_CXXFLAGS="$AM_CXXFLAGS -I$with_readline/include"
  AM_LDFLAGS="$AM_LDFLAGS -L$with_readline/lib"
fi

AC_SUBST([AM_CFLAGS])
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_CPPFLAGS])
AC_SUBST([AM_LDFLAGS])
AC_SUBST([CFLAGS])
AC_SUBST([CXXFLAGS])
AC_SUBST([CPPFLAGS])

# Setup comilation/linking flags for library checks
OLDCPPFLAGS=$CPPFLAGS
CPPFLAGS=$CXXFLAGS
OLDLDFLAGS=$LDFLAGS
LDFLAGS="$LDFLAGS $AM_LDFLAGS"
CFLAGS="$CFLAGS $AM_CFLAGS"

# Check for GMP header
GMP_HEADER_FOUND=1
if test $NONSTDGMPPATH = 1 ; then
	AC_CHECK_HEADERS($with_gmp/include/gmp.h,
			 ,
			 [AC_MSG_ERROR([ The GMP header gmp.h was not found.])])

else
	AC_CHECK_HEADERS(gmp.h,
			 ,
			 [AC_MSG_ERROR([ The GMP header gmp.h was not found.])])
fi
# Check for GMP library
AC_CHECK_LIB(gmp, __gmpz_init, ,[AC_MSG_ERROR([GMP library not found])])

# Check for readline library
AX_LIB_READLINE
# Restore original flags
CPPFLAGS=$OLDCPPFLAGS
LDFLAGS=$OLDLDFLAGS

#
# List of directories to include
#
config_includedirs="-I\${top_srcdir}/src -I\${top_srcdir}/src/minisat/mtl -I\${top_srcdir}/src/minisat/core -I\${top_srcdir}/src/simplifiers -I\${top_srcdir}/src/common -I\${top_srcdir}/src/egraph -I\${top_srcdir}/src/sorts -I\${top_srcdir}/src/symbols -I\${top_srcdir}/src/pterms -I\${top_srcdir}/src/logics -I\${top_srcdir}/src/smtsolvers -I\${top_srcdir}/src/cnfizers -I\${top_srcdir}/src/proof -I\${top_srcdir}/src/api -I\${top_srcdir}/src/tsolvers -I\${top_srcdir}/src/tsolvers/emptysolver -I\${top_srcdir}/src/tsolvers/bvsolver -I\${top_srcdir}/src/tsolvers/bvsolver/minisatp -I\${top_srcdir}/src/tsolvers/lrasolver -I\${top_srcdir}/src/tsolvers/liasolver -I\${top_srcdir}/src/tsolvers/ctsolver -I\${top_srcdir}/src/tsolvers/axdiffsolver -I\${top_srcdir}/src/tsolvers/dlsolver -I\${top_srcdir}/src/attributes"

AM_CFLAGS="$AM_CFLAGS ${config_includedirs} ${def_flags} ${comp_flags}"
AM_CXXFLAGS="$AM_CXXFLAGS ${config_includedirs} ${def_flags} ${comp_flags}"
AC_SUBST(config_includedirs)

AC_CONFIG_FILES([ \
		  Makefile \
		  src/Makefile \
		  src/parsers/Makefile \
		  src/parsers/smt2new/Makefile \
		  src/pterms/Makefile \
		  src/cnfizers/Makefile \
		  src/simplifiers/Makefile \
		  src/smtsolvers/Makefile \
		  src/proof/Makefile \
		  src/common/Makefile \
		  src/egraph/Makefile \
		  src/sorts/Makefile \
		  src/logics/Makefile \
		  src/symbols/Makefile \
		  src/tsolvers/Makefile \
		  src/tsolvers/emptysolver/Makefile \
		  src/tsolvers/axdiffsolver/Makefile \
		  src/tsolvers/bvsolver/Makefile \
		  src/tsolvers/bvsolver/minisatp/Makefile \
		  src/tsolvers/lrasolver/Makefile \
		  src/tsolvers/ctsolver/Makefile \
		  src/tsolvers/dlsolver/Makefile \
		  src/api/Makefile \
		  test/Makefile \
		  ])

AC_DEFINE_UNQUOTED([CONFIGTIME_DEFFLAGS], ["`echo ${def_flags} | sed 's/  */ /g'`]", [C define flags passed after configure])
AC_DEFINE_UNQUOTED([CONFIGTIME_COMPFLAGS], ["$comp_flags"], [C++ compiler flags of interest])

AC_OUTPUT

echo "=================================================="
echo "Configuring with C define flags"
echo " ${def_flags}" | sed 's/  */\n /g'
echo
echo "Configuring with [AM_CPPFLAGS] = $AM_CPPFLAGS"
echo "Configuring with [AM_CXXFLAGS] = $AM_CXXFLAGS"
echo "Configuring with [AM_CFLAGS] = $AM_CFLAGS"
echo "=================================================="


