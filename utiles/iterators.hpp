/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:49:57 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/01 16:11:42 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <cstddef>

// std::iterator_traits
namespace ft
{
    struct random_access_iterator_tag {};
    
    template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
    struct iterator 
    {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };
    template <class Iterator> 
    class iterator_traits
    {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };
    template <class T> 
    class iterator_traits<T*>
    {
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef random_access_iterator_tag  iterator_category;
    };
    template <class T> 
    class iterator_traits<const T*>
    {
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef const T*                    pointer;
        typedef const T&                    reference;
        typedef random_access_iterator_tag  iterator_category;
    };

    template <class Iterator>
    class reverse_iterator : public iterator<
                        typename iterator_traits<Iterator>::iterator_category,
                        typename iterator_traits<Iterator>::value_type,
                        typename iterator_traits<Iterator>::difference_type,
                        typename iterator_traits<Iterator>::pointer,
                        typename iterator_traits<Iterator>::reference>
    {
    protected:
        Iterator current;
        
    public:
        typedef Iterator                                                iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename iterator_traits<Iterator>::reference           reference;
        typedef typename iterator_traits<Iterator>::pointer             pointer;
        typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
        typedef typename iterator_traits<Iterator>::value_type          value_type;

    public:
        // canonical form 
        constexpr reverse_iterator(): current(){}
        constexpr explicit reverse_iterator(Iterator x) : current(x){}
        template <class U> constexpr reverse_iterator(const reverse_iterator<U>& u): current(u.base()){}
        template <class U> reverse_iterator& operator=(const reverse_iterator<U>& u)
        {
            this->current = u.base();
            return *this;
        }

        // other class functions
        constexpr Iterator base() const 
        {
            return this->current;
        };
        reference operator*() const 
        {
            return *(this->current - 1);
        };
        pointer   operator->() const
        {
            return &(operator*());
        };
        reverse_iterator& operator++()
        {
            --this->current;
            return *this;
        };
        reverse_iterator  operator++(int)
        {
            reverse_iterator tmp(*this);
            --this->current;
            return (tmp);
        };
        reverse_iterator& operator--()
        {
            ++this->current;
            return *this;
        };
        reverse_iterator  operator--(int)
        {
            reverse_iterator tmp(*this);
            ++this->current;
            return (tmp);
        };
        reverse_iterator  operator+ (difference_type n) const
        {
            return reverse_iterator(this->current - n);
        };
        reverse_iterator& operator+=(difference_type n)
        {
            this->current -= n;
            return *this;
        }
        reverse_iterator  operator- (difference_type n) const
        {
            return reverse_iterator(this->current + n);
        };
        reverse_iterator& operator-=(difference_type n)
        {
            this->current += n;
            return *this;
        }
        reference operator[](difference_type n) const
        {
            return *(*this + n);
        }
    };


































    template <class Iterator>
    class random_access_iterator
    {
    public:
        typedef Iterator                                                      iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type        value_type;
        typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
        typedef typename iterator_traits<iterator_type>::pointer           pointer;
        typedef typename iterator_traits<iterator_type>::reference         reference;
    private:
        iterator_type current;
    public:
        random_access_iterator() 
                    : current{}
    
        {
    
            __get_db()->__insert_i(this);
    
        }
        template <class _Up>  
            random_access_iterator(const random_access_iterator<_Up>& __u,
                typename enable_if<is_convertible<_Up, iterator_type>::value>::type* = 0) 
                : current(__u.base())
        {
    
            __get_db()->__iterator_copy(this, &__u);
    
        }
   
        reference operator*() const 
        {
    
            _LIBCPP_ASSERT(__get_const_db()->__dereferenceable(this),
                        "Attempted to dereference a non-dereferenceable iterator");
    
            return *current;
        }
        pointer  operator->() const 
        {
    
            _LIBCPP_ASSERT(__get_const_db()->__dereferenceable(this),
                        "Attempted to dereference a non-dereferenceable iterator");
    
            return (pointer)_VSTD::addressof(*current);
        }
        random_access_iterator& operator++() 
        {
    
            _LIBCPP_ASSERT(__get_const_db()->__dereferenceable(this),
                        "Attempted to increment non-incrementable iterator");
    
            ++current;
            return *this;
        }
        random_access_iterator  operator++(int) 
            {random_access_iterator __tmp(*this); ++(*this); return __tmp;}

        random_access_iterator& operator--() 
        {
    
            _LIBCPP_ASSERT(__get_const_db()->__decrementable(this),
                        "Attempted to decrement non-decrementable iterator");
    
            --current;
            return *this;
        }
        random_access_iterator  operator--(int) 
            {random_access_iterator __tmp(*this); --(*this); return __tmp;}
        random_access_iterator  operator+ (difference_type __n) const 
            {random_access_iterator __w(*this); __w += __n; return __w;}
        random_access_iterator& operator+=(difference_type __n) 
        {
    
            _LIBCPP_ASSERT(__get_const_db()->__addable(this, __n),
                    "Attempted to add/subtract iterator outside of valid range");
    
            current += __n;
            return *this;
        }
        random_access_iterator  operator- (difference_type __n) const 
            {return *this + (-__n);}
        random_access_iterator& operator-=(difference_type __n) 
            {*this += -__n; return *this;}
        reference    operator[](difference_type __n) const 
        {
    
            _LIBCPP_ASSERT(__get_const_db()->__subscriptable(this, __n),
                    "Attempted to subscript iterator outside of valid range");
    
            return current[__n];
        }

        iterator_type base() const  {return current;}

    private:
    

        random_access_iterator(iterator_type __x)  : current(__x) {}
    

        template <class _Up> friend class random_access_iterator;
        template <class _Tp, ptrdiff_t> 
        template <class _Iter1, class _Iter2>
         friend
        bool
        operator==(const random_access_iterator<_Iter1>&, const random_access_iterator<_Iter2>&) ;

        template <class _Iter1, class _Iter2>
         friend
        bool
        operator<(const random_access_iterator<_Iter1>&, const random_access_iterator<_Iter2>&) ;

        template <class _Iter1, class _Iter2>
         friend
        bool
        operator!=(const random_access_iterator<_Iter1>&, const random_access_iterator<_Iter2>&) ;

        template <class _Iter1, class _Iter2>
         friend
        bool
        operator>(const random_access_iterator<_Iter1>&, const random_access_iterator<_Iter2>&) ;

        template <class _Iter1, class _Iter2>
         friend
        bool
        operator>=(const random_access_iterator<_Iter1>&, const random_access_iterator<_Iter2>&) ;

        template <class _Iter1, class _Iter2>
         friend
        bool
        operator<=(const random_access_iterator<_Iter1>&, const random_access_iterator<_Iter2>&) ;

     
        template <class _Iter1, class _Iter2>
         friend
        auto
        operator-(const random_access_iterator<_Iter1>& __x, const random_access_iterator<_Iter2>& __y) 
        -> decltype(__x.base() - __y.base());
    
        template <class _Iter1, class _Iter2>
         friend
        typename random_access_iterator<_Iter1>::difference_type
        operator-(const random_access_iterator<_Iter1>&, const random_access_iterator<_Iter2>&) ;
    

        template <class _Iter1>
         friend
        random_access_iterator<_Iter1>
        operator+(typename random_access_iterator<_Iter1>::difference_type, random_access_iterator<_Iter1>) ;

        template <class _Ip, class _Op> friend _Op copy(_Ip, _Ip, _Op);
        template <class _B1, class _B2> friend _B2 copy_backward(_B1, _B1, _B2);
        template <class _Ip, class _Op> friend _Op move(_Ip, _Ip, _Op);
        template <class _B1, class _B2> friend _B2 move_backward(_B1, _B1, _B2);

   
    
    };

    
}