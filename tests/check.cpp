
template <class _T1, class _T2>
struct _LIBCPP_TEMPLATE_VIS pair
{
    typedef _T1 first_type;
    typedef _T2 second_type;

    _T1 first;
    _T2 second;

    pair(pair const&) = default;
    pair(pair&&) = default;

    template <bool _Val>
    using _EnableB = typename enable_if<_Val, bool>::type;

    struct _CheckArgs {
      template <class _U1, class _U2>
      static constexpr bool __enable_default() {
          return is_default_constructible<_U1>::value
              && is_default_constructible<_U2>::value;
      }

      template <class _U1, class _U2>
      static constexpr bool __enable_explicit() {
          return is_constructible<first_type, _U1>::value
              && is_constructible<second_type, _U2>::value
              && (!is_convertible<_U1, first_type>::value
                  || !is_convertible<_U2, second_type>::value);
      }

      template <class _U1, class _U2>
      static constexpr bool __enable_implicit() {
          return is_constructible<first_type, _U1>::value
              && is_constructible<second_type, _U2>::value
              && is_convertible<_U1, first_type>::value
              && is_convertible<_U2, second_type>::value;
      }
    };

    template <bool _MaybeEnable>
    using _CheckArgsDep = typename conditional<
      _MaybeEnable, _CheckArgs, __check_tuple_constructor_fail>::type;

    struct _CheckTupleLikeConstructor {
        template <class _Tuple>
        static constexpr bool __enable_implicit() {
            return __tuple_convertible<_Tuple, pair>::value;
        }

        template <class _Tuple>
        static constexpr bool __enable_explicit() {
            return __tuple_constructible<_Tuple, pair>::value
               && !__tuple_convertible<_Tuple, pair>::value;
        }

        template <class _Tuple>
        static constexpr bool __enable_assign() {
            return __tuple_assignable<_Tuple, pair>::value;
        }
    };

    template <class _Tuple>
    using _CheckTLC = typename conditional<
        __tuple_like_with_size<_Tuple, 2>::value
            && !is_same<typename decay<_Tuple>::type, pair>::value,
        _CheckTupleLikeConstructor,
        __check_tuple_constructor_fail
    >::type;

    template<bool _Dummy = true, _EnableB<
            _CheckArgsDep<_Dummy>::template __enable_default<_T1, _T2>()
    > = false>
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
    pair() _NOEXCEPT_(is_nothrow_default_constructible<first_type>::value &&
                      is_nothrow_default_constructible<second_type>::value)
        : first(), second() {}

    template <bool _Dummy = true, _EnableB<
             _CheckArgsDep<_Dummy>::template __enable_explicit<_T1 const&, _T2 const&>()
    > = false>
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    explicit pair(_T1 const& __t1, _T2 const& __t2)
        _NOEXCEPT_(is_nothrow_copy_constructible<first_type>::value &&
                   is_nothrow_copy_constructible<second_type>::value)
        : first(__t1), second(__t2) {}

    template<bool _Dummy = true, _EnableB<
            _CheckArgsDep<_Dummy>::template __enable_implicit<_T1 const&, _T2 const&>()
    > = false>
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    pair(_T1 const& __t1, _T2 const& __t2)
        _NOEXCEPT_(is_nothrow_copy_constructible<first_type>::value &&
                   is_nothrow_copy_constructible<second_type>::value)
        : first(__t1), second(__t2) {}

    template<class _U1, class _U2, _EnableB<
             _CheckArgs::template __enable_explicit<_U1, _U2>()
    > = false>
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    explicit pair(_U1&& __u1, _U2&& __u2)
        _NOEXCEPT_((is_nothrow_constructible<first_type, _U1>::value &&
                    is_nothrow_constructible<second_type, _U2>::value))
        : first(_VSTD::forward<_U1>(__u1)), second(_VSTD::forward<_U2>(__u2)) {}

    template<class _U1, class _U2, _EnableB<
            _CheckArgs::template __enable_implicit<_U1, _U2>()
    > = false>
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    pair(_U1&& __u1, _U2&& __u2)
        _NOEXCEPT_((is_nothrow_constructible<first_type, _U1>::value &&
                    is_nothrow_constructible<second_type, _U2>::value))
        : first(_VSTD::forward<_U1>(__u1)), second(_VSTD::forward<_U2>(__u2)) {}

    template<class _U1, class _U2, _EnableB<
            _CheckArgs::template __enable_explicit<_U1 const&, _U2 const&>()
    > = false>
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    explicit pair(pair<_U1, _U2> const& __p)
        _NOEXCEPT_((is_nothrow_constructible<first_type, _U1 const&>::value &&
                    is_nothrow_constructible<second_type, _U2 const&>::value))
        : first(__p.first), second(__p.second) {}

    template<class _U1, class _U2, _EnableB<
            _CheckArgs::template __enable_implicit<_U1 const&, _U2 const&>()
    > = false>
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    pair(pair<_U1, _U2> const& __p)
        _NOEXCEPT_((is_nothrow_constructible<first_type, _U1 const&>::value &&
                    is_nothrow_constructible<second_type, _U2 const&>::value))
        : first(__p.first), second(__p.second) {}

    template<class _U1, class _U2, _EnableB<
            _CheckArgs::template __enable_explicit<_U1, _U2>()
    > = false>
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    explicit pair(pair<_U1, _U2>&&__p)
        _NOEXCEPT_((is_nothrow_constructible<first_type, _U1&&>::value &&
                    is_nothrow_constructible<second_type, _U2&&>::value))
        : first(_VSTD::forward<_U1>(__p.first)), second(_VSTD::forward<_U2>(__p.second)) {}

    template<class _U1, class _U2, _EnableB<
            _CheckArgs::template __enable_implicit<_U1, _U2>()
    > = false>
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    pair(pair<_U1, _U2>&& __p)
        _NOEXCEPT_((is_nothrow_constructible<first_type, _U1&&>::value &&
                    is_nothrow_constructible<second_type, _U2&&>::value))
        : first(_VSTD::forward<_U1>(__p.first)), second(_VSTD::forward<_U2>(__p.second)) {}

    template<class _Tuple, _EnableB<
            _CheckTLC<_Tuple>::template __enable_explicit<_Tuple>()
    > = false>
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    explicit pair(_Tuple&& __p)
        : first(_VSTD::get<0>(_VSTD::forward<_Tuple>(__p))),
          second(_VSTD::get<1>(_VSTD::forward<_Tuple>(__p))) {}

    template<class _Tuple, _EnableB<
            _CheckTLC<_Tuple>::template __enable_implicit<_Tuple>()
    > = false>
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX11
    pair(_Tuple&& __p)
        : first(_VSTD::get<0>(_VSTD::forward<_Tuple>(__p))),
          second(_VSTD::get<1>(_VSTD::forward<_Tuple>(__p))) {}

    template <class... _Args1, class... _Args2>
    _LIBCPP_INLINE_VISIBILITY
    pair(piecewise_construct_t __pc,
         tuple<_Args1...> __first_args, tuple<_Args2...> __second_args)
        _NOEXCEPT_((is_nothrow_constructible<first_type, _Args1...>::value &&
                    is_nothrow_constructible<second_type, _Args2...>::value))
        : pair(__pc, __first_args, __second_args,
                typename __make_tuple_indices<sizeof...(_Args1)>::type(),
                typename __make_tuple_indices<sizeof...(_Args2) >::type()) {}

    _LIBCPP_INLINE_VISIBILITY
    pair& operator=(typename conditional<
                        is_copy_assignable<first_type>::value &&
                        is_copy_assignable<second_type>::value,
                    pair, __nat>::type const& __p)
        _NOEXCEPT_(is_nothrow_copy_assignable<first_type>::value &&
                   is_nothrow_copy_assignable<second_type>::value)
    {
        first = __p.first;
        second = __p.second;
        return *this;
    }

    _LIBCPP_INLINE_VISIBILITY
    pair& operator=(typename conditional<
                        is_move_assignable<first_type>::value &&
                        is_move_assignable<second_type>::value,
                    pair, __nat>::type&& __p)
        _NOEXCEPT_(is_nothrow_move_assignable<first_type>::value &&
                   is_nothrow_move_assignable<second_type>::value)
    {
        first = _VSTD::forward<first_type>(__p.first);
        second = _VSTD::forward<second_type>(__p.second);
        return *this;
    }

    template <class _Tuple, _EnableB<
            _CheckTLC<_Tuple>::template __enable_assign<_Tuple>()
     > = false>
    _LIBCPP_INLINE_VISIBILITY
    pair& operator=(_Tuple&& __p) {
        first = _VSTD::get<0>(_VSTD::forward<_Tuple>(__p));
        second = _VSTD::get<1>(_VSTD::forward<_Tuple>(__p));
        return *this;
    }
#endif

    _LIBCPP_INLINE_VISIBILITY
    void
    swap(pair& __p) _NOEXCEPT_(__is_nothrow_swappable<first_type>::value &&
                               __is_nothrow_swappable<second_type>::value)
    {
        using _VSTD::swap;
        swap(first,  __p.first);
        swap(second, __p.second);
    }
private:

#ifndef _LIBCPP_CXX03_LANG
    template <class... _Args1, class... _Args2, size_t... _I1, size_t... _I2>
        _LIBCPP_INLINE_VISIBILITY
        pair(piecewise_construct_t,
             tuple<_Args1...>& __first_args, tuple<_Args2...>& __second_args,
             __tuple_indices<_I1...>, __tuple_indices<_I2...>);
#endif
};

