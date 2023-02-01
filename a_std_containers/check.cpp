  template <class Iterator>
    class random_access_iterator : public iterator<
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
        constexpr random_access_iterator(): current(){}
        constexpr explicit random_access_iterator(Iterator x) : current(x){}
        template <class U> constexpr random_access_iterator(const random_access_iterator<U>& u): current(u.base()){}
        template <class U> random_access_iterator& operator=(const random_access_iterator<U>& u)
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
        random_access_iterator& operator++()
        {
            --this->current;
            return *this;
        };
        random_access_iterator  operator++(int)
        {
            random_access_iterator tmp(*this);
            --this->current;
            return (tmp);
        };
        random_access_iterator& operator--()
        {
            ++this->current;
            return *this;
        };
        random_access_iterator  operator--(int)
        {
            random_access_iterator tmp(*this);
            ++this->current;
            return (tmp);
        };
        random_access_iterator  operator+ (difference_type n) const
        {
            return random_access_iterator(this->current - n);
        };
        random_access_iterator& operator+=(difference_type n)
        {
            this->current -= n;
            return *this;
        }
        random_access_iterator  operator- (difference_type n) const
        {
            return random_access_iterator(this->current + n);
        };
        random_access_iterator& operator-=(difference_type n)
        {
            this->current += n;
            return *this;
        }
        reference operator[](difference_type n) const
        {
            return *(*this + n);
        }
    };
