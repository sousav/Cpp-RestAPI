#if not defined BEASTHTTP_BASE_CONFIG_HXX
#define BEASTHTTP_BASE_CONFIG_HXX

#include <boost/config.hpp>

#define USE_MAKE_SHARED 1

#if USE_MAKE_SHARED == 1
#define BEASTHTTP_USE_MAKE_SHARED
#endif

#if __cplusplus >= 201402L
#if not defined BOOST_NO_CXX14_GENERIC_LAMBDAS
#define BEASTHTTP_CXX14_GENERIC_LAMBDAS
#endif // BOOST_NO_CXX14_GENERIC_LAMBDAS

#if not defined BOOST_NO_CXX14_CONSTEXPR
#define BEASTHTTP_CXX14_CONSTEXPR
#endif

#endif // __cplusplus >= 201402L

#if __cplusplus >= 201703L
#define BEASTHTTP_CXX17_SHARED_MUTEX
#define BEASTHTTP_CXX17_FOLD_EXPR

#if not defined BOOST_NO_CXX17_HDR_OPTIONAL
#define BEASTHTTP_CXX17_OPTIONAL
#endif // BOOST_NO_CXX17_HDR_OPTIONAL

#if not defined BOOST_NO_CXX17_IF_CONSTEXPR
#define BEASTHTTP_CXX17_IF_CONSTEXPR
#endif // BOOST_NO_CXX17_IF_CONSTEXPR
#endif // __cplusplus >= 201703L

#endif // BEASTHTTP_BASE_CONFIG_HXX