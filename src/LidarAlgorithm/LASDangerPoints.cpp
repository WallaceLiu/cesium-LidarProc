 / /  
 / /   C r e a t e d   b y   w u w e i   o n   1 8 - 1 - 2 4 .  
 / /  
 # i n c l u d e < o m p . h >  
 # i n c l u d e " g d a l _ p r i v . h "  
 # i n c l u d e   " L A S D a n g e r P o i n t s . h "  
  
 # i n c l u d e " . . / L i d a r A l g o r i t h m / P o i n t P r o c A l g o r i t h m . h "  
  
 t y p e d e f   l o n g   D a n g e r L e v e l ;  
 s t a t i c   o m p _ l o c k _ t   m u t e l o c k ;  
  
 s t a t i c   v o i d   S e t P o i n t C o l o r ( L A S P o i n t   & p n t ,   s h o r t   r ,   s h o r t   g ,   s h o r t   b )  
 {  
 	 p n t . m _ c o l o r E x t . R e d   =   r ;  
 	 p n t . m _ c o l o r E x t . G r e e n   =   g ;  
 	 p n t . m _ c o l o r E x t . B l u e   =   b ;  
 }  
  
 s t a t i c   v o i d   i n l i n e   S e t P o i n t C o l o r L e v e l ( L A S P o i n t   & p n t ,   D a n g e r L e v e l   l e v e l )  
 {  
 	 s w i t c h   ( l e v e l )  
 	 {  
 	 c a s e   1 :  
 	 	 S e t P o i n t C o l o r ( p n t ,   1 5 3 ,   0 ,   2 5 5 ) ;  
 	 	 b r e a k ;  
 	 c a s e   2 :  
 	 	 S e t P o i n t C o l o r ( p n t ,   2 5 5 ,   1 5 3 ,   0 ) ;  
 	 	 b r e a k ;  
 	 c a s e   3 :  
 	 	 S e t P o i n t C o l o r ( p n t ,   2 5 5 ,   0 ,   0 ) ;  
 	 	 b r e a k ;  
 	 d e f a u l t : 
 	 	 b r e a k ;  
 	 }  
 }  
  
 l o n g   L A S D a n g e r P o i n t s : : L A S D a n g e r P o i n t s _ R a n g e ( c o n s t   P o i n t 3 D   * p n t ,   f l o a t   d i s t a n c e ,   I L A S D a t a s e t *   d a t a s e t V e g t e r a i n ,   v e c t o r < i n t >   & r e c t I d s )  
 {  
 	 R e c t 2 D   r e c t ;  
 	 r e c t . m i n x   =   p n t - > x   -   d i s t a n c e ;   r e c t . m a x x   =   p n t - > x   +   d i s t a n c e ;  
 	 r e c t . m i n y   =   p n t - > y   -   d i s t a n c e ;   r e c t . m a x y   =   p n t - > y   +   d i s t a n c e ;  
 	 d a t a s e t V e g t e r a i n - > L A S D a t a s e t _ S e a r c h ( 0 ,   r e c t ,   r e c t I d s ) ;  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s : : L A S D a n g e r P o i n t s _ P e r P o i n t ( f l o a t   d i s t a n c e ,   c o n s t   P o i n t 3 D   * p n t ,   I L A S D a t a s e t   * d a t a s e t V e g t e r i a n )  
 {  
 	 v e c t o r < i n t >   r e c t R a n g e I d x ;  
 	 L A S D a n g e r P o i n t s _ R a n g e ( p n t ,   d i s t a n c e ,   d a t a s e t V e g t e r i a n ,   r e c t R a n g e I d x ) ;  
  
 	 f o r   ( i n t   i   =   0 ;   i < r e c t R a n g e I d x . s i z e ( ) ;   + + i )  
 	 {  
 	 	 i n t   i n d   =   r e c t R a n g e I d x [ i ] ;  
 	 	 f o r   ( i n t   j   =   0 ;   j   < d a t a s e t V e g t e r i a n - > m _ l a s R e c t a n g l e s [ i n d ] . m _ l a s P o i n t s _ n u m b e r s ;   + + j )   {  
 	 	 	 c o n s t   P o i n t 3 D   t m p P n t   =   d a t a s e t V e g t e r i a n - > m _ l a s R e c t a n g l e s [ i n d ] . m _ l a s P o i n t s [ j ] . m _ v e c 3 d ;  
 	 	 	 i f   ( p n t - > D i s t a n c e ( t m p P n t ) < d i s t a n c e )   {  
 	 	 	 	 d a t a s e t V e g t e r i a n - > m _ l a s R e c t a n g l e s [ i n d ] . m _ l a s P o i n t s [ j ] . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 	 	 }  
 	 	 }  
 	 }  
  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s : : L A S D a n g e r P o i n t s _ P e r P o i n t ( f l o a t   * d i s t a n c e ,   i n t   d a n g e r S e c t i o n N u m b e r ,   c o n s t   P o i n t 3 D   * p n t , I L A S D a t a s e t   * d a t a s e t V e g t e r i a n )   {  
  
 	 v e c t o r < i n t >   r e c t R a n g e I d x ;  
 	 L A S D a n g e r P o i n t s _ R a n g e ( p n t ,   d i s t a n c e [ d a n g e r S e c t i o n N u m b e r   -   1 ] ,   d a t a s e t V e g t e r i a n ,   r e c t R a n g e I d x ) ;  
 	 i f   ( d a n g e r S e c t i o n N u m b e r   ! =   3 )  
 	 {  
 	 	 p r i n t f ( " p l z   i n p u t   3   n u m b e r   r a n g e \ n " ) ;  
 	 	 r e t u r n   - 1 ;  
 	 }  
  
 	 / / o n l y   c o n s i d e r   3   t y p e   o f   c l a s s e s  
 	 f o r   ( i n t   i   =   0 ;   i < r e c t R a n g e I d x . s i z e ( ) ;   + + i )  
 	 {  
 	 	 i n t   i n d   =   r e c t R a n g e I d x [ i ] ;  
 	 	 f o r   ( i n t   j   =   0 ;   j   < d a t a s e t V e g t e r i a n - > m _ l a s R e c t a n g l e s [ i n d ] . m _ l a s P o i n t s _ n u m b e r s ;   + + j )   {  
  
 	 	 	 L A S P o i n t   & l a s p n t   =   d a t a s e t V e g t e r i a n - > m _ l a s R e c t a n g l e s [ i n d ] . m _ l a s P o i n t s [ j ] ;  
 	 	 	 c o n s t   P o i n t 3 D   t m p P n t   =   l a s p n t . m _ v e c 3 d ;  
 	 	 	 i n t   c l a s s T y p e   =   l a s p n t . m _ c l a s s i f y ;  
  
 	 	 	 i f   ( c l a s s T y p e > e l c D a n g e r & & c l a s s T y p e < e l c D a n g e r E n d )  
 	 	 	 {  
 	 	 	 	 i f   ( p n t - > D i s t a n c e ( t m p P n t ) < d i s t a n c e [ 0 ]   & &   c l a s s T y p e > e l c D a n g e r   +   1 )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 1 ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   2 5 5 ,   0 ,   0 ) ;  
 	 	 	 	 }  
 	 	 	 	 e l s e   i f   ( p n t - > D i s t a n c e ( t m p P n t ) < d i s t a n c e [ 1 ]   & &   c l a s s T y p e > e l c D a n g e r   +   2 )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 2 ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   2 5 5 ,   1 5 3 ,   0 ) ;  
 	 	 	 	 }  
 	 	 	 	 e l s e   i f   ( p n t - > D i s t a n c e ( t m p P n t ) < d i s t a n c e [ 2 ]   & &   c l a s s T y p e > e l c D a n g e r   +   3 )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   1 5 3 ,   0 ,   2 5 5 ) ;  
 	 	 	 	 }  
 	 	 	 }  
 	 	 	 e l s e  
 	 	 	 {  
 	 	 	 	 d o u b l e   d i s   =   p n t - > D i s t a n c e ( t m p P n t ) ;  
 	 	 	 	 i f   ( d i s < d i s t a n c e [ 0 ] )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 1 ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   2 5 5 ,   0 ,   0 ) ;  
 	 	 	 	 }  
 	 	 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 1 ] )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 2 ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   2 5 5 ,   1 5 3 ,   0 ) ;  
 	 	 	 	 }  
 	 	 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 2 ] )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 3 ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   1 5 3 ,   0 ,   2 5 5 ) ;  
 	 	 	 	 }  
 	 	 	 }  
 	 	 }  
 	 }  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s : : L A S D a n g e r P o i n t s _ D e t e c t ( f l o a t   d i s t a n c e ,   I L A S D a t a s e t   * d a t a s e t L i n e ,   I L A S D a t a s e t   * d a t a s e t V e g t e r a i n )  
 {  
 	 i n t   r s   =   0 ;  
 	 i n t   n u m L i n e R e c t s   =   d a t a s e t L i n e - > m _ n u m R e c t a n g l e s ;  
 	 f o r   ( i n t   i   =   0 ;   i < n u m L i n e R e c t s ;   + + i )  
 	 {  
 	 	 i n t   n u m P n t I n R e c t   =   d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s _ n u m b e r s ;  
 	 	 f o r   ( i n t   j   =   0 ;   j < n u m P n t I n R e c t ;   + + j )  
 	 	 {  
 	 	 	 p r i n t f ( " \ r % d - % d " ,   n u m P n t I n R e c t ,   j ) ;  
 	 	 	 c o n s t   P o i n t 3 D   l i n e P n t   =   d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s [ j ] . m _ v e c 3 d ;  
 	 	 	 r s   =   r s   |   L A S D a n g e r P o i n t s _ P e r P o i n t ( d i s t a n c e ,   & l i n e P n t ,   d a t a s e t V e g t e r a i n ) ;  
 	 	 }  
 	 	 p r i n t f ( " \ n " ) ;  
 	 }  
 	 r e t u r n   r s ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s : : L A S D a n g e r P o i n t s _ D e t e c t ( f l o a t *   d i s t a n c e ,   i n t   d a n g e r S e c t i o n N u m b e r ,   I L A S D a t a s e t *   d a t a s e t L i n e ,   I L A S D a t a s e t *   d a t a s e t V e g t e r a i n )    
 {  
 	 i n t   r s   =   0 ;  
 	 i n t   n u m L i n e R e c t s   =   d a t a s e t L i n e - > m _ n u m R e c t a n g l e s ;  
 	 f o r   ( i n t   i   =   0 ;   i < n u m L i n e R e c t s ;   + + i )  
 	 {  
 	 	 i n t   n u m P n t I n R e c t   =   d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s _ n u m b e r s ;  
 	 	 p r i n t f ( " % d - % d " ,   n u m L i n e R e c t s ,   i ) ;  
 	 	 f o r   ( i n t   j   =   0 ;   j < n u m P n t I n R e c t ;   + + j )  
 	 	 {  
 	 	 	 c o n s t   P o i n t 3 D   l i n e P n t   =   d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s [ j ] . m _ v e c 3 d ;  
 	 	 	 r s   =   r s   |   L A S D a n g e r P o i n t s _ P e r P o i n t ( d i s t a n c e ,   d a n g e r S e c t i o n N u m b e r ,   & l i n e P n t ,   d a t a s e t V e g t e r a i n ) ;  
 	 	 }  
 	 	 p r i n t f ( " \ n " ) ;  
 	 }  
 	 / / t r i m   t o   e l c D a n g e r   t o   e x p o r t   a n d   p r o c e s s  
 	 f o r   ( i n t   i   =   0 ;   i < d a t a s e t V e g t e r a i n - > m _ n u m R e c t a n g l e s ;   + + i )  
 	 {  
 	 	 i n t   n u m P n t I n R e c t   =   d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s _ n u m b e r s ;  
 	 	 f o r   ( i n t   j   =   0 ;   j < n u m P n t I n R e c t ;   + + j )  
 	 	 {  
 	 	 	 L A S P o i n t   & p n t   =   d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s [ j ] ;  
 	 	 	 i n t   c l a s s T y p e   =   p n t . m _ c l a s s i f y ;  
 	 	 	 i f   ( c l a s s T y p e > e l c D a n g e r & & c l a s s T y p e < e l c D a n g e r E n d )   {  
 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 	 	 }  
 	 	 }  
 	 }  
  
 	 r e t u r n   r s ;  
 }  
  
 / *  
 / / d e l e t e d   b y   F r a n k . W u   � � � � � � � � � �  
 l o n g   L A S D a n g e r P o i n t s : : L A D D a n g e r P o i n t s _ S p l i t D a n g e r ( I L A S D a t a s e t   * d a t a s e t V e g t e r a i n ,   c o n s t   c h a r   * p a t h S p l i t )  
 {  
 	 L i d a r M e m R e a d e r   l i d a r O p t ;  
 	 l i d a r O p t . L i d a r R e a d e r _ E x p o r t ( p a t h S p l i t ,   d a t a s e t V e g t e r a i n ,   ( i n t ) e l c D a n g e r ) ;  
 	 r e t u r n   0 ;  
 }  
 * /  
  
 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
 / / F L A N N   D a n g e r   D e t e c t  
 l o n g   L A S D a n g e r P o i n t s F l a n n : : L A S D a n g e r P o i n t s _ P e r P o i n t ( f l o a t   d i s t a n c e ,   c o n s t   P o i n t 3 D *   p n t , k d _ t r e e   & t r e e V e g e , v e c t o r < i n t >   m a p p e r ,   I L A S D a t a s e t *   d a t a s e t )  
 {  
 	 d o u b l e   q u e r y _ p t [ 3 ]   =   {   p n t - > x ,   p n t - > y ,   p n t - > z   } ;  
 	 / / c o n s t   s i z e _ t   n u m _ r e s u l t s   =   1 0 ;  
 	 / / s i z e _ t   r e t _ i n d e x [ 1 0 ] ;  
 	 / / d o u b l e   o u t _ d i s t _ s q r [ 1 0 ] ;  
 	 / / K N N R e s u l t S e t < d o u b l e >   r e s u l t S e t ( n u m _ r e s u l t s ) ;  
 	 c o n s t   d o u b l e   r a d i u s   =   d i s t a n c e ;  
 	 s t d : : v e c t o r < s t d : : p a i r < s i z e _ t ,   d o u b l e >   >   i n d i c e s _ d i s t s ;  
 	 R a d i u s R e s u l t S e t < d o u b l e ,   s i z e _ t >   r e s u l t S e t ( r a d i u s ,   i n d i c e s _ d i s t s ) ;  
  
 	 / / r e s u l t S e t . i n i t ( r e t _ i n d e x ,   o u t _ d i s t _ s q r ) ;  
 	 t r e e V e g e . f i n d N e i g h b o r s ( r e s u l t S e t ,   & q u e r y _ p t [ 0 ] ,   S e a r c h P a r a m s ( ) ) ;  
  
 	 f o r   ( i n t   i   =   0 ;   i   <   r e s u l t S e t . m _ i n d i c e s _ d i s t s . s i z e ( ) ;   + + i )  
 	 {  
 	 	 / / f o r   d e b u g  
 	 	 / / p r i n t f ( " r e t _ i n d e x = % d   o u t _ d i s t _ s q r = % l f \ n " ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . f i r s t ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . s e c o n d ) ; 
 	 	 i n t   m a p I d x   =   m a p p e r [ r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . f i r s t ] ;  
 	 	 c o n s t   L A S I n d e x   & i d x   =   d a t a s e t V e g t e r a i n - > m _ L A S P o i n t I D [ m a p I d x ] ;  
 	 	 L A S P o i n t   & p n t   =   d a t a s e t - > m _ l a s R e c t a n g l e s [ i d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ i d x . p o i n t _ i d x _ i n R e c t ] ;  
 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 }  
  
 	 r e t u r n   0 ;  
 }  
 
 
 l o n g   L A S D a n g e r P o i n t s F l a n n : : L A S D a n g e r P o i n t s _ P e r P o i n t ( f l o a t   d i s t a n c e ,   c o n s t   P o i n t 3 D *   p n t , k d _ t r e e   & t r e e V e g e ,   I L A S D a t a s e t *   d a t a s e t V e g t e r a i n )  
 {  
 	 d o u b l e   q u e r y _ p t [ 3 ]   =   {   p n t - > x ,   p n t - > y ,   p n t - > z   } ;  
 	 / / c o n s t   s i z e _ t   n u m _ r e s u l t s   =   1 0 ;  
 	 / / s i z e _ t   r e t _ i n d e x [ 1 0 ] ;  
 	 / / d o u b l e   o u t _ d i s t _ s q r [ 1 0 ] ;  
 	 / / K N N R e s u l t S e t < d o u b l e >   r e s u l t S e t ( n u m _ r e s u l t s ) ;  
 	 c o n s t   d o u b l e   r a d i u s   =   d i s t a n c e ;  
 	 s t d : : v e c t o r < s t d : : p a i r < s i z e _ t ,   d o u b l e >   >   i n d i c e s _ d i s t s ;  
 	 R a d i u s R e s u l t S e t < d o u b l e ,   s i z e _ t >   r e s u l t S e t ( r a d i u s ,   i n d i c e s _ d i s t s ) ;  
  
 	 / / r e s u l t S e t . i n i t ( r e t _ i n d e x ,   o u t _ d i s t _ s q r ) ;  
 	 t r e e V e g e . f i n d N e i g h b o r s ( r e s u l t S e t ,   & q u e r y _ p t [ 0 ] ,   S e a r c h P a r a m s ( ) ) ;  
  
 	 f o r   ( i n t   i   =   0 ;   i   <   r e s u l t S e t . m _ i n d i c e s _ d i s t s . s i z e ( ) ;   + + i )  
 	 {  
 	 	 / / f o r   d e b u g  
 	 	 / / p r i n t f ( " r e t _ i n d e x = % d   o u t _ d i s t _ s q r = % l f \ n " ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . f i r s t ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . s e c o n d ) ;  
 	 	 c o n s t   L A S I n d e x   & i d x   =   d a t a s e t V e g t e r a i n - > m _ L A S P o i n t I D [ r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . f i r s t ] ;  
 	 	 L A S P o i n t   & p n t   =   d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ i d x . p o i n t _ i d x _ i n R e c t ] ;  
 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 }  
  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s F l a n n : : L A S D a n g e r P o i n t s _ P e r P o i n t ( f l o a t *   d i s t a n c e ,   i n t   d a n g e r S e c t i o n N u m b e r ,   c o n s t   P o i n t 3 D *   p n t ,     k d _ t r e e   & t r e e V e g e ,   I L A S D a t a s e t *   d a t a s e t V e g t e r a i n )  
 {  
 	 d o u b l e   q u e r y _ p t [ 3 ]   =   {   p n t - > x ,   p n t - > y ,   p n t - > z   } ;  
 	 / / c o n s t   s i z e _ t   n u m _ r e s u l t s   =   1 0 ;  
 	 / / s i z e _ t   r e t _ i n d e x [ 1 0 ] ;  
 	 / / d o u b l e   o u t _ d i s t _ s q r [ 1 0 ] ;  
 	 / / K N N R e s u l t S e t < d o u b l e >   r e s u l t S e t ( n u m _ r e s u l t s ) ;  
 	 / / � � � � � � � � � � � � � � � �  
 	 c o n s t   d o u b l e   r a d i u s   =   d i s t a n c e [ 2 ] ;  
 	 s t d : : v e c t o r < s t d : : p a i r < s i z e _ t ,   d o u b l e >   >   i n d i c e s _ d i s t s ;  
 	 R a d i u s R e s u l t S e t < d o u b l e ,   s i z e _ t >   r e s u l t S e t ( r a d i u s ,   i n d i c e s _ d i s t s ) ;  
  
 	 / / r e s u l t S e t . i n i t ( r e t _ i n d e x ,   o u t _ d i s t _ s q r ) ;  
 	 t r e e V e g e . f i n d N e i g h b o r s ( r e s u l t S e t ,   & q u e r y _ p t [ 0 ] ,   S e a r c h P a r a m s ( ) ) ;  
  
 	 f o r   ( i n t   i   =   0 ;   i   <   r e s u l t S e t . m _ i n d i c e s _ d i s t s . s i z e ( ) ;   + + i )  
 	 {  
 	 	 / / f o r   d e b u g  
 	 	 / / p r i n t f ( " r e t _ i n d e x = % d   o u t _ d i s t _ s q r = % l f \ n " ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . f i r s t ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . s e c o n d ) ;  
 	 	 c o n s t   L A S I n d e x   & i d x   =   d a t a s e t V e g t e r a i n - > m _ L A S P o i n t I D [ r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . f i r s t ] ;  
 	 	 L A S P o i n t   & p n t   =   d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ i d x . p o i n t _ i d x _ i n R e c t ] ;  
 	  
 	 	 i n t   c l a s s T y p e   =   p n t . m _ c l a s s i f y ;  
 	 	 d o u b l e   d i s   =   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . s e c o n d ;  
 	 	 i f   ( c l a s s T y p e > e l c D a n g e r & & c l a s s T y p e < e l c D a n g e r E n d )  
 	 	 {  
 	 	 	 i f   ( d i s < d i s t a n c e [ 0 ]   & &   c l a s s T y p e > e l c D a n g e r   +   1 )  
 	 	 	 {  
 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 1 ;  
 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t , 3 ) ;  
 	 	 	 }  
 	 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 1 ]   & &   c l a s s T y p e > e l c D a n g e r   +   2 )  
 	 	 	 {  
 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 2 ;  
 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t , 2 ) ;  
 	 	 	 }  
 	 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 2 ]   & &   c l a s s T y p e > e l c D a n g e r   +   3 )  
 	 	 	 {  
 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t ,   1 ) ;  
 	 	 	 }  
 	 	 }  
 	 	 e l s e  
 	 	 {  
 	 	 	 d o u b l e   d i s   =   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . s e c o n d ;  
 	 	 	 i f   ( d i s < d i s t a n c e [ 0 ] )  
 	 	 	 {  
 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 1 ;  
 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t , 3 ) ;  
 	 	 	 }  
 	 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 1 ] )  
 	 	 	 {  
 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 2 ;  
 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t , 2 ) ;  
 	 	 	 }  
 	 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 2 ] )  
 	 	 	 {  
 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 3 ;  
 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t ,   1 ) ;  
 	 	 	 }  
 	 	 }  
 	 }  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s F l a n n : : L A S D a n g e r P o i n t s _ D e t e c t ( f l o a t   d i s t a n c e ,   I L A S D a t a s e t *   d a t a s e t L i n e ,   I L A S D a t a s e t *   d a t a s e t V e g t e r a i n )  
 {  
 	 d o u b l e   d i s   =   d i s t a n c e   *   d i s t a n c e ;  
 	 / / � � � � � � � � � � � �  
 	 s t d : : v e c t o r < P o i n t 3 D >   p n t C l o u d ;  
 	 f o r   ( i n t   i   =   0 ;   i   <   d a t a s e t V e g t e r a i n - > m _ t o t a l R e a d L a s N u m b e r ;   + + i )  
 	 {  
 	 	 c o n s t   L A S I n d e x   & i d x   =   d a t a s e t V e g t e r a i n - > m _ L A S P o i n t I D [ i ] ;  
 	 	 p n t C l o u d . p u s h _ b a c k ( d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ i d x . p o i n t _ i d x _ i n R e c t ] . m _ v e c 3 d ) ;  
 	 }  
  
 	 c o n s t   P C A d a p t o r   p c A d a p t o r P n t s ( p n t C l o u d ) ;  
 	 k d _ t r e e   t r e e V e g e I n d e x ( 3 ,   p c A d a p t o r P n t s ,   K D T r e e S i n g l e I n d e x A d a p t o r P a r a m s ( 1 0 ) ) ;  
 	 t r e e V e g e I n d e x . b u i l d I n d e x ( ) ;  
  
 	 / / � � � � � � � � � � � � � � F L A N N  
 	 f o r   ( i n t   i   =   0 ;   i   <   d a t a s e t L i n e - > m _ t o t a l R e a d L a s N u m b e r ;   + + i )  
 	 {  
 	 	 p r i n t f ( " \ r p r o c e s s   p o i n t s   % d / % d " ,   d a t a s e t L i n e - > m _ t o t a l R e a d L a s N u m b e r ,   i   +   1 ) ;  
 	 	 c o n s t   L A S I n d e x   & i d x   =   d a t a s e t L i n e - > m _ L A S P o i n t I D [ i ] ;  
 	 	 c o n s t   P o i n t 3 D   & p n t = d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ i d x . p o i n t _ i d x _ i n R e c t ] . m _ v e c 3 d ;  
 	 	 L A S D a n g e r P o i n t s _ P e r P o i n t ( d i s ,   & p n t ,   t r e e V e g e I n d e x ,   d a t a s e t V e g t e r a i n ) ;  
 	 }  
 	 p r i n t f ( " \ n " ) ;  
  
 	 p n t C l o u d . c l e a r ( ) ;  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s F l a n n : : L A S D a n g e r P o i n t s _ D e t e c t ( f l o a t *   d i s t a n c e ,   i n t   d a n g e r S e c t i o n N u m b e r ,   I L A S D a t a s e t *   d a t a s e t L i n e ,   I L A S D a t a s e t *   d a t a s e t V e g t e r a i n )  
 {  
 	 f l o a t   * d i s   =   n e w   f l o a t [ d a n g e r S e c t i o n N u m b e r ] ;  
 	 f o r   ( i n t   i   =   0 ;   i   <   d a n g e r S e c t i o n N u m b e r ;   + + i )  
 	 	 d i s [ i ]   =   d i s t a n c e [ i ]   *   d i s t a n c e [ i ] ;  
  
 	 / / � � � � � � � � � � � �  
 	 s t d : : v e c t o r < P o i n t 3 D >   p n t C l o u d ;  
 	 f o r   ( i n t   i   =   0 ;   i   <   d a t a s e t V e g t e r a i n - > m _ t o t a l R e a d L a s N u m b e r ;   + + i )  
 	 {  
 	 	 c o n s t   L A S I n d e x   & i d x   =   d a t a s e t V e g t e r a i n - > m _ L A S P o i n t I D [ i ] ;  
 	 	 p n t C l o u d . p u s h _ b a c k ( d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ i d x . p o i n t _ i d x _ i n R e c t ] . m _ v e c 3 d ) ;  
 	 }  
  
 	 c o n s t   P C A d a p t o r   p c A d a p t o r P n t s ( p n t C l o u d ) ;  
 	 k d _ t r e e   t r e e V e g e I n d e x ( 3 ,   p c A d a p t o r P n t s ,   K D T r e e S i n g l e I n d e x A d a p t o r P a r a m s ( 1 0 ) ) ;  
 	 t r e e V e g e I n d e x . b u i l d I n d e x ( ) ;  
  
 	 / / � � � � � � � � � � � � � � F L A N N  
 	 f o r   ( i n t   i   =   0 ;   i   <   d a t a s e t L i n e - > m _ t o t a l R e a d L a s N u m b e r ;   + + i )  
 	 {  
 	 	 p r i n t f ( " \ r p r o c e s s   p o i n t s   % d / % d " ,   d a t a s e t L i n e - > m _ t o t a l R e a d L a s N u m b e r ,   i   +   1 ) ;  
 	 	 c o n s t   L A S I n d e x   & i d x   =   d a t a s e t L i n e - > m _ L A S P o i n t I D [ i ] ;  
 	 	 c o n s t   P o i n t 3 D   & p n t   =   d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ i d x . p o i n t _ i d x _ i n R e c t ] . m _ v e c 3 d ;  
 	 	 L A S D a n g e r P o i n t s _ P e r P o i n t ( d i s , d a n g e r S e c t i o n N u m b e r ,   & p n t ,   t r e e V e g e I n d e x ,   d a t a s e t V e g t e r a i n ) ;  
 	 }  
 	 p r i n t f ( " \ n " ) ;  
 	 f o r   ( i n t   i   =   0 ;   i   <   d a t a s e t V e g t e r a i n - > m _ t o t a l R e a d L a s N u m b e r ;   + + i )  
 	 {  
 	 	 c o n s t   L A S I n d e x   & i d x   =   d a t a s e t V e g t e r a i n - > m _ L A S P o i n t I D [ i ] ;  
 	 	 L A S P o i n t   & p n t   =   d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ i d x . p o i n t _ i d x _ i n R e c t ] ;  
 	 	 i n t   	 v e c t o r < P o i n t 3 D >   p o i n t V e g e t a t i o n ; 
 	 v e c t o r < i n t >   p o i n t V e g e t a t i o n M a p p e r ; 
 c l a s s T y p e   =   p n t . m _ c l a s s i f y ;  
 	 	 i f   ( c l a s s T y p e   >   e l c D a n g e r & & c l a s s T y p e   <   e l c D a n g e r E n d )  
 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 }  
 	 d e l e t e [ ] d i s ;   d i s   =   n u l l p t r ;  
 	 p n t C l o u d . c l e a r ( ) ;  
 	 r e t u r n   0 ;  
 }  
 
 
 l o n g   L A S D a n g e r P o i n t s F l a n n : : L A S D a n g e r P o i n t s _ D e t e c t ( f l o a t   d i s t a n c e , I L A S D a t a s e t *   d a t a s e t ) 
 { 
 	 v e c t o r < P o i n t 3 D >   p o i n t V e g e t a t i o n ; 
 	 v e c t o r < i n t >   p o i n t V e g e t a t i o n M a p p e r ; 
 	 
 	 v e c t o r < P o i n t 3 D >   p o i n t L i n e ; 
 	 v e c t o r < i n t >   p o i n t L i n e M a p p e r ; 
 	 
 	 / /��S�i��p�T�[�~�p�S�Qvf \Qs|� 
 	 f o r   ( i n t   i   =   0 ;   i   <   d a t a s e t - > m _ t o t a l R e a d L a s N u m b e r ;   + + i )  
 	 {  
 	 	 c o n s t   L A S I n d e x   & i d x   =   d a t a s e t - > m _ L A S P o i n t I D [ i ] ; 
 	 	 c o n s t   L A S P o i n t   & p t   = d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ i d x . p o i n t _ i d x _ i n R e c t ] ;    
 	 	 i f ( p t . m _ c l a s s i f y   = =   e l c V e g e t a t i o n ) 
 	 	 { 
 	 	 	 p o i n t V e g e t a t i o n . p u s h _ b a c k ( p t . m _ v e c 3 d ) ; 
 	 	 	 p o i n t V e g e t a t i o n M a p p e r . p u s h _ b a c k ( i ) ; 
 	 	 } 
 	 	 e l s e   i f ( p t . m _ c l a s s i f y   = =   e l c L i n e ) 
 	 	 { 
 	 	 	 p o i n t L i n e . p u s h _ b a c k ( p t . m _ v e c 3 d ) ; 
 	 	 	 p o i n t L i n e M a p p e r . p u s h _ b a c k ( i ) 
 	 	 }  
 	 } 
 	  
 	 / /g�^� K D T r e e 
 	 c o n s t   P C A d a p t o r   p c A d a p t o r P n t s ( p o i n t V e g e t a t i o n ) ;  
 	 k d _ t r e e   t r e e V e g e I n d e x ( 3 ,   p c A d a p t o r P n t s ,   K D T r e e S i n g l e I n d e x A d a p t o r P a r a m s ( 1 0 ) ) ;  
 	 t r e e V e g e I n d e x . b u i l d I n d e x ( ) ;  
 
 	 f o r   ( i n t   i   =   0 ;   i   <   p o i n t V e g e t a i o n . s i z e ( ) ;   + + i )  
 	 {  
 	 	 p r i n t f ( " \ r p r o c e s s   p o i n t s   % d / % d " ,   p o i n t V e g e t a i o n . s i z e ( ) ,   i   +   1 ) ;  
 	 	 L A S D a n g e r P o i n t s _ P e r P o i n t ( d i s ,   & p n t ,   t r e e V e g e I n d e x ,   d a t a s e t ) ;  
 	 } 
 	 
 	 p o i n t V e g e t a t i o n . c l e a r ( ) ; 
 	 p o i n t V e g e t a t i o n M a p p e r . c l e a r ( ) ; 
 	 p o i n t L i n e . c l e a r ( ) ; 
 	 p o i n t L i n e M a p p e r . c l e a r ( ) ; 
 	 
 	 r e t u r n   0 ; 
 } 
  
 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
 / / F L A N N   B l o c k   D a n g e r   D e t e c t  
 l o n g   L A S D a n g e r P o i n t s F l a n n B l o c k : : L A S D a n g e r P o i n t s _ P e r P o i n t ( f l o a t   d i s t a n c e ,   c o n s t   P o i n t 3 D *   p n t ,   I L A S D a t a s e t *   d a t a s e t V e g t e r a i n )  
 {  
 	 / / � � � � � � � � � � � � B l o c k  
 	 v e c t o r < i n t >   r e c t I d x ;  
 	 L A S D a n g e r P o i n t s _ R a n g e ( p n t ,   d i s t a n c e ,   d a t a s e t V e g t e r a i n ,   r e c t I d x ) ;  
  
 	 / / � � � � � � B l o c k � � � � � � � � � � � � � � � � � �  
 	 / / � � � � � � � � � � � � � � � � � �  
 	 f o r   ( a u t o   i d x   :   r e c t I d x )    
 	 {  
 	 	 d o u b l e   q u e r y _ p t [ 3 ]   =   {   p n t - > x ,   p n t - > y ,   p n t - > z   } ;  
 	 	 c o n s t   d o u b l e   r a d i u s   =   d i s t a n c e ;  
 	 	 s t d : : v e c t o r < s t d : : p a i r < s i z e _ t ,   d o u b l e >   >   i n d i c e s _ d i s t s ;  
 	 	 R a d i u s R e s u l t S e t < d o u b l e ,   s i z e _ t >   r e s u l t S e t ( r a d i u s ,   i n d i c e s _ d i s t s ) ;  
 	 	 i f   ( d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x ] . m _ l a s P o i n t s _ n u m b e r s   <   0 )  
 	 	 	 c o n t i n u e ;  
 	 	 e l s e  
 	 	 {  
 	 	 	 d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x ] . m _ b l o c k _ t r e e - > f i n d N e i g h b o r s ( r e s u l t S e t ,   & q u e r y _ p t [ 0 ] ,   S e a r c h P a r a m s ( ) ) ;  
 	 	 	 f o r   ( i n t   i   =   0 ;   i   <   r e s u l t S e t . m _ i n d i c e s _ d i s t s . s i z e ( ) ;   + + i )  
 	 	 	 {  
 	 	 	 	 i n t   p n t I d x   =   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . f i r s t ;  
 	 	 	 	 / / f o r   d e b u g  
 	 	 	 	 / / p r i n t f ( " r e t _ i n d e x = % d   o u t _ d i s t _ s q r = % l f \ n " ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . f i r s t ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . s e c o n d ) ;  
 	 	 	 	 L A S P o i n t   & p n t   =   d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x ] . m _ l a s P o i n t s [ p n t I d x ] ;  
 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 	 	 }  
 	 	 }  
 	 }  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s F l a n n B l o c k : : L A S D a n g e r P o i n t s _ P e r P o i n t ( f l o a t *   d i s t a n c e ,   i n t   d a n g e r S e c t i o n N u m b e r ,   c o n s t   P o i n t 3 D *   p n t ,   I L A S D a t a s e t *   d a t a s e t V e g t e r a i n )  
 {  
 	 / / � � � � � � � � � � � � B l o c k  
 	 v e c t o r < i n t >   r e c t I d x ;  
 	 L A S D a n g e r P o i n t s _ R a n g e ( p n t ,   d i s t a n c e [ d a n g e r S e c t i o n N u m b e r - 1 ] ,   d a t a s e t V e g t e r a i n ,   r e c t I d x ) ;  
  
 	 / / � � � � � � B l o c k � � � � � � � � � � � � � � � � � �  
 	 / / � � � � � � � � � � � � � � � � � �  
 	 f o r   ( a u t o   i d x   :   r e c t I d x )  
 	 {  
 	 	 d o u b l e   q u e r y _ p t [ 3 ]   =   {   p n t - > x ,   p n t - > y ,   p n t - > z   } ;  
 	 	 c o n s t   d o u b l e   r a d i u s   =   d i s t a n c e [ d a n g e r S e c t i o n N u m b e r   -   1 ] ;  
 	 	 s t d : : v e c t o r < s t d : : p a i r < s i z e _ t ,   d o u b l e >   >   i n d i c e s _ d i s t s ;  
 	 	 R a d i u s R e s u l t S e t < d o u b l e ,   s i z e _ t >   r e s u l t S e t ( r a d i u s ,   i n d i c e s _ d i s t s ) ;  
 	 	 i f   ( d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x ] . m _ l a s P o i n t s _ n u m b e r s   < =   0 )  
 	 	 	 c o n t i n u e ;  
 	 	 e l s e  
 	 	 {  
 	 	 	 d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x ] . m _ b l o c k _ t r e e - > f i n d N e i g h b o r s ( r e s u l t S e t ,   & q u e r y _ p t [ 0 ] ,   S e a r c h P a r a m s ( ) ) ;  
 	 	 	 / / p r i n t f ( " % d \ n " ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s . s i z e ( ) ) ;  
 	 	 	 f o r   ( i n t   i   =   0 ;   i   <   r e s u l t S e t . m _ i n d i c e s _ d i s t s . s i z e ( ) ;   + + i )  
 	 	 	 {  
 	 	 	 	 i n t   p n t I d x   =   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . f i r s t ;  
 	 	 	 	 / / f o r   d e b u g  
 	 	 	 	 / / p r i n t f ( " r e t _ i n d e x = % d   o u t _ d i s t _ s q r = % l f \ n " ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . f i r s t ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . s e c o n d ) ;  
 	 	 	 	 L A S P o i n t   & p n t   =   d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i d x ] . m _ l a s P o i n t s [ p n t I d x ] ;  
 	 	 	 	 i n t   c l a s s T y p e   =   p n t . m _ c l a s s i f y ;  
 	 	 	 	 d o u b l e   d i s   =   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . s e c o n d ;  
 	 	 	 	 i f   ( c l a s s T y p e > e l c D a n g e r & & c l a s s T y p e < e l c D a n g e r E n d )  
 	 	 	 	 {  
 	 	 	 	 	 i f   ( d i s < d i s t a n c e [ 0 ]   & &   c l a s s T y p e > e l c D a n g e r   +   1 )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 1 ;  
 	 	 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t , 3 ) ;  
 	 	 	 	 	 }  
 	 	 	 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 1 ]   & &   c l a s s T y p e > e l c D a n g e r   +   2 )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 2 ;  
 	 	 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t , 2 ) ;  
 	 	 	 	 	 }  
 	 	 	 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 2 ]   & &   c l a s s T y p e > e l c D a n g e r   +   3 )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 	 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t ,   1 ) ;  
 	 	 	 	 	 }  
 	 	 	 	 }  
 	 	 	 	 e l s e  
 	 	 	 	 {  
 	 	 	 	 	 d o u b l e   d i s   =   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . s e c o n d ;  
 	 	 	 	 	 i f   ( d i s < d i s t a n c e [ 0 ] )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 1 ;  
 	 	 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t , 3 ) ;  
 	 	 	 	 	 }  
 	 	 	 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 1 ] )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 2 ;  
 	 	 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t , 2 ) ;  
 	 	 	 	 	 }  
 	 	 	 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 2 ] )  
 	 	 	 	 	 {  
 	 	 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 3 ;  
 	 	 	 	 	 	 S e t P o i n t C o l o r L e v e l ( p n t ,   1 ) ;  
 	 	 	 	 	 }  
 	 	 	 	 }  
 	 	 	 }  
 	 	 }  
 	 }  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s F l a n n B l o c k : : L A S D a n g e r P o i n t s _ P e r P o i n t ( f l o a t *   d i s t a n c e ,   i n t   d a n g e r S e c t i o n N u m b e r ,   c o n s t   P o i n t 3 D   p n t ,    
 	 k d _ t r e e   & t r e e L i n e ,   c o n s t   L A S I n d e x   t r e e I d x ,   I L A S D a t a s e t *   d a t a s e t )  
 {  
 	 d o u b l e   q u e r y _ p t [ 3 ]   =   {   p n t . x ,   p n t . y ,   p n t . z   } ;  
 	 c o n s t   s i z e _ t   n u m _ r e s u l t s   =   1 ;  
 	 s i z e _ t   r e t _ i n d e x ;  
 	 d o u b l e   o u t _ d i s t _ s q r ;  
 	 K N N R e s u l t S e t < d o u b l e >   r e s u l t S e t ( n u m _ r e s u l t s ) ;  
 	 r e s u l t S e t . i n i t ( & r e t _ i n d e x ,   & o u t _ d i s t _ s q r ) ;  
 	 t r e e L i n e . f i n d N e i g h b o r s ( r e s u l t S e t ,   & q u e r y _ p t [ 0 ] ,   S e a r c h P a r a m s ( 1 0 ) ) ;  
  
 	 L A S P o i n t   & l a s P n t   =   d a t a s e t - > m _ l a s R e c t a n g l e s [ t r e e I d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ t r e e I d x . p o i n t _ i d x _ i n R e c t ] ;  
 	 i n t   c l a s s T y p e   =   l a s P n t . m _ c l a s s i f y ;  
 	 d o u b l e   d i s   =   o u t _ d i s t _ s q r ;  
  
 	 o m p _ s e t _ l o c k ( & m u t e l o c k ) ;  
 	 i f   ( c l a s s T y p e > e l c D a n g e r & & c l a s s T y p e < e l c D a n g e r E n d )  
 	 {  
 	 	 i f   ( d i s < d i s t a n c e [ 0 ]   & &   c l a s s T y p e > e l c D a n g e r   +   1 )  
 	 	 {  
 	 	 	 l a s P n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 1 ;  
 	 	 	 S e t P o i n t C o l o r L e v e l ( l a s P n t ,   3 ) ;  
 	 	 }  
 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 1 ]   & &   c l a s s T y p e > e l c D a n g e r   +   2 )  
 	 	 {  
 	 	 	 l a s P n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 2 ;  
 	 	 	 S e t P o i n t C o l o r L e v e l ( l a s P n t ,   2 ) ;  
 	 	 }  
 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 2 ]   & &   c l a s s T y p e > e l c D a n g e r   +   3 )  
 	 	 {  
 	 	 	 l a s P n t . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 	 	 S e t P o i n t C o l o r L e v e l ( l a s P n t ,   1 ) ;  
 	 	 }  
 	 }  
 	 e l s e  
 	 {  
 	 	 i f   ( d i s < d i s t a n c e [ 0 ] )  
 	 	 {  
 	 	 	 l a s P n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 1 ;  
 	 	 	 S e t P o i n t C o l o r L e v e l ( l a s P n t ,   3 ) ;  
 	 	 }  
 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 1 ] )  
 	 	 {  
 	 	 	 l a s P n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 2 ;  
 	 	 	 S e t P o i n t C o l o r L e v e l ( l a s P n t ,   2 ) ;  
 	 	 }  
 	 	 e l s e   i f   ( d i s < d i s t a n c e [ 2 ] )  
 	 	 {  
 	 	 	 l a s P n t . m _ c l a s s i f y   =   e l c D a n g e r L e v e l 3 ;  
 	 	 	 S e t P o i n t C o l o r L e v e l ( l a s P n t ,   1 ) ;  
 	 	 }  
 	 }  
 	 o m p _ u n s e t _ l o c k ( & m u t e l o c k ) ;  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s F l a n n B l o c k : : L A S D a n g e r P o i n t s _ D e t e c t ( f l o a t   d i s t a n c e ,   I L A S D a t a s e t *   d a t a s e t L i n e ,   I L A S D a t a s e t *   d a t a s e t V e g t e r a i n )  
 {  
 	 i n t   r s   =   0 ;  
 	 i n t   n u m L i n e R e c t s   =   d a t a s e t L i n e - > m _ n u m R e c t a n g l e s ;  
 	 f o r   ( i n t   i   =   0 ;   i < n u m L i n e R e c t s ;   + + i )  
 	 {  
 	 	 i n t   n u m P n t I n R e c t   =   d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s _ n u m b e r s ;  
 	 	 f o r   ( i n t   j   =   0 ;   j < n u m P n t I n R e c t ;   + + j )  
 	 	 {  
 	 	 	 p r i n t f ( " \ r % d - % d " ,   n u m P n t I n R e c t ,   j ) ;  
 	 	 	 c o n s t   P o i n t 3 D   l i n e P n t   =   d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s [ j ] . m _ v e c 3 d ;  
 	 	 	 r s   =   r s   |   L A S D a n g e r P o i n t s _ P e r P o i n t ( d i s t a n c e ,   & l i n e P n t ,   d a t a s e t V e g t e r a i n ) ;  
 	 	 }  
 	 	 p r i n t f ( " \ n " ) ;  
 	 }  
 	 r e t u r n   r s ;  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s F l a n n B l o c k : : L A S D a n g e r P o i n t s _ D e t e c t ( f l o a t *   d i s t a n c e ,   i n t   d a n g e r S e c t i o n N u m b e r ,   I L A S D a t a s e t *   d a t a s e t L i n e ,   I L A S D a t a s e t *   d a t a s e t V e g t e r a i n )  
 {  
 	 i n t   r s   =   0 ;  
 	 i n t   n u m L i n e R e c t s   =   d a t a s e t L i n e - > m _ n u m R e c t a n g l e s ;  
 	 f o r   ( i n t   i   =   0 ;   i < n u m L i n e R e c t s ;   + + i )  
 	 {  
 	 	 i n t   n u m P n t I n R e c t   =   d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s _ n u m b e r s ;  
 	 	 f o r   ( i n t   j   =   0 ;   j < n u m P n t I n R e c t ;   + + j )  
 	 	 {  
 	 	 	 c o n s t   P o i n t 3 D   l i n e P n t   =   d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s [ j ] . m _ v e c 3 d ;  
 	 	 	 r s   =   r s   |   L A S D a n g e r P o i n t s _ P e r P o i n t ( d i s t a n c e ,   d a n g e r S e c t i o n N u m b e r ,   & l i n e P n t ,   d a t a s e t V e g t e r a i n ) ;  
 	 	 }  
 	 }  
 	 p r i n t f ( " \ n " ) ;  
  
 	 / / t r i m   t o   e l c D a n g e r   t o   e x p o r t   a n d   p r o c e s s  
 	 f o r   ( i n t   i   =   0 ;   i < d a t a s e t V e g t e r a i n - > m _ n u m R e c t a n g l e s ;   + + i )  
 	 {  
 	 	 i n t   n u m P n t I n R e c t   =   d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s _ n u m b e r s ;  
 	 	 f o r   ( i n t   j   =   0 ;   j < n u m P n t I n R e c t ;   + + j )  
 	 	 {  
 	 	 	 L A S P o i n t   & p n t   =   d a t a s e t V e g t e r a i n - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s [ j ] ;  
 	 	 	 i n t   c l a s s T y p e   =   p n t . m _ c l a s s i f y ;  
 	 	 	 i f   ( c l a s s T y p e > e l c D a n g e r & & c l a s s T y p e < e l c D a n g e r E n d )   {  
 	 	 	 	 p n t . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 	 	 }  
 	 	 }  
 	 }  
  
 	 r e t u r n   r s ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s F l a n n B l o c k : : L A S D a n g e r P o i n t s _ D e t e c t ( f l o a t *   d i s t a n c e ,   i n t   d a n g e r S e c t i o n N u m b e r ,   I L A S D a t a s e t *   d a t a s e t ,   d o u b l e   s e g D i s ,   P o i n t 2 D *   p t T o w e r ,   s t d : : v e c t o r < L A S I n d e x >   & p n t I d x )  
 {  
 	 t r y  
 	 {  
 	 	 P o i n t 3 D s     p t L i n e ;  
 	 	 s t d : : v e c t o r < L A S I n d e x >   l i n e I d x ,   t r e e I d x ;  
 	 	 / / t r y   m e m o r y   c o m s u m e  
 	 	 f o r   ( i n t   i   =   0 ;   i   <   d a t a s e t - > m _ t o t a l R e a d L a s N u m b e r ;   + + i )  
 	 	 {  
 	 	 	 c o n s t   L A S I n d e x   & l a s I d x   =   d a t a s e t - > m _ L A S P o i n t I D [ i ] ;  
 	 	 	 c o n s t   L A S P o i n t   & l a s P n t   =   d a t a s e t - > m _ l a s R e c t a n g l e s [ l a s I d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ l a s I d x . p o i n t _ i d x _ i n R e c t ] ;  
 	 	 	 i f   ( l a s P n t . m _ c l a s s i f y   = =   e l c L i n e )  
 	 	 	 {  
 	 	 	 	 p t L i n e . p u s h _ b a c k ( l a s P n t . m _ v e c 3 d ) ;  
 	 	 	 	 l i n e I d x . p u s h _ b a c k ( l a s I d x ) ;  
 	 	 	 }  
 	 	 	 e l s e   i f   ( l a s P n t . m _ c l a s s i f y   = =   e l c V e g e t a t i o n )  
 	 	 	 {  
 	 	 	 	 t r e e I d x . p u s h _ b a c k ( l a s I d x ) ;  
 	 	 	 }  
 	 	 }  
  
 	 	 / / c o n s t r u c t   k d t r e e   f r o m   t h e   d a t a s e t  
 	 	 t y p e d e f   P o i n t C l o u d A d a p t o r < s t d : : v e c t o r < P o i n t 3 D > >   P C A d a p t o r ;  
 	 	 c o n s t   P C A d a p t o r   p c A d a p t o r L i n e P n t s ( p t L i n e ) ;  
  
 	 	 t y p e d e f   K D T r e e S i n g l e I n d e x A d a p t o r < L 2 _ S i m p l e _ A d a p t o r < d o u b l e ,   P C A d a p t o r > ,   P C A d a p t o r ,   3 >   k d _ t r e e ;  
 	 	 k d _ t r e e   t r e e L i n e I n d e x ( 3 ,   p c A d a p t o r L i n e P n t s ,   K D T r e e S i n g l e I n d e x A d a p t o r P a r a m s ( 1 0 ) ) ;  
 	 	 t r e e L i n e I n d e x . b u i l d I n d e x ( ) ;  
 	 	 o m p _ i n i t _ l o c k ( & m u t e l o c k ) ;  
 # p r a g m a   o m p   p a r a l l e l   f o r  
 	 	 f o r   ( i n t   i   =   0 ;   i   <   t r e e I d x . s i z e ( ) ;   + + i )  
 	 	 {  
 	 	 	 c o n s t   L A S I n d e x   & l a s I d x   =   t r e e I d x [ i ] ;  
 	 	 	 c o n s t   P o i n t 3 D   & l a s P n t   =   d a t a s e t - > m _ l a s R e c t a n g l e s [ l a s I d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ l a s I d x . p o i n t _ i d x _ i n R e c t ] . m _ v e c 3 d ;  
 	 	 	 L A S D a n g e r P o i n t s _ P e r P o i n t ( d i s t a n c e ,   d a n g e r S e c t i o n N u m b e r ,   l a s P n t ,   t r e e L i n e I n d e x ,   t r e e I d x [ i ] ,   d a t a s e t ) ;  
 	 	 }  
 	 	 o m p _ d e s t r o y _ l o c k ( & m u t e l o c k ) ;  
 	 	 / / c l e a r   m e m o r y    
 	 	 l i n e I d x . c l e a r ( ) ;  
  
 	 	 / / d a n g e r   p o i n t s   r e p r e s e n t  
 	 	 P o i n t 3 D s   p t D a n g e r ;  
 	 	 s t d : : v e c t o r < L A S I n d e x >   d a n g e r I d x ;  
 	 	 f o r   ( i n t   i   =   0 ;   i   <   t r e e I d x . s i z e ( ) ;   + + i )  
 	 	 {  
 	 	 	 c o n s t   L A S I n d e x   & l a s I d x   =   t r e e I d x [ i ] ;  
 	 	 	 t r y   {  
 	 	 	 	 L A S P o i n t   & l a s P n t   =   d a t a s e t - > m _ l a s R e c t a n g l e s [ l a s I d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ l a s I d x . p o i n t _ i d x _ i n R e c t ] ;  
 	 	 	 	 p r i n t f ( " \ r % d   % d   % d " ,   i ,   l a s I d x . r e c t a n g l e _ i d x ,   l a s I d x . p o i n t _ i d x _ i n R e c t ) ;  
 	 	 	 	 i f   ( l a s P n t . m _ c l a s s i f y > e l c D a n g e r   & &   l a s P n t . m _ c l a s s i f y < e l c D a n g e r E n d )  
 	 	 	 	 {  
 	 	 	 	 	 d a n g e r I d x . p u s h _ b a c k ( l a s I d x ) ;  
 	 	 	 	 	 l a s P n t . m _ c l a s s i f y   =   e l c D a n g e r ;  
 	 	 	 	 	 p t D a n g e r . p u s h _ b a c k ( l a s P n t . m _ v e c 3 d ) ;  
 	 	 	 	 }  
 	 	 	 }  
 	 	 	 c a t c h   ( e x c e p t i o n   e )  
 	 	 	 {  
 	 	 	 	 p r i n t f ( " % d   % d   % d \ n " , i ,   l a s I d x . r e c t a n g l e _ i d x ,   l a s I d x . p o i n t _ i d x _ i n R e c t ) ;  
 	 	 	 }  
  
 	 	 }  
 	 	 t r e e I d x . c l e a r ( ) ;  
 	 	 i n t   * t y p e   =   n e w   i n t [ p t D a n g e r . s i z e ( ) ] ;  
 	 	 L a s A l g o r i t h m : : P o i n t C l o u d S e g m e n t   p n t C l o u d S e g ;  
 	 	 i n t   s e g N u m b e r   =   p n t C l o u d S e g . P o i n t C l o u d S e g m e n t _ D B S c a n ( p t D a n g e r ,   t y p e ,   s e g D i s ) ;  
  
 	 	 / / v e c t o r   i s   s e q u e n c e  
 	 	 v e c t o r < i n t >   t y p e P n t N u m b e r , i d x T y p e ;  
 	 	 v e c t o r < d o u b l e >   d i s T y p e ;  
 	 	 t y p e P n t N u m b e r . r e s i z e ( s e g N u m b e r ) ; d i s T y p e . r e s i z e ( s e g N u m b e r ) ; i d x T y p e . r e s i z e ( s e g N u m b e r ) ;  
 	 	 m e m s e t ( & t y p e P n t N u m b e r ,   0 ,   s i z e o f ( i n t ) * s e g N u m b e r ) ;  
 	 	 m e m s e t ( & t y p e P n t N u m b e r ,   _ M A X _ L I M I T _ ,   s i z e o f ( d o u b l e ) * s e g N u m b e r ) ;  
  
 	 	 / / s e l e c t   a   r e p r e s e n t   p o i n t   f o r   e a c h   s e g  
 	 	 f o r   ( i n t   i   =   0 ;   i   <   p t D a n g e r . s i z e ( ) ;   + + i )  
 	 	 {  
 	 	 	 i n t   t p I d x   =   t y p e [ i ] ; t y p e P n t N u m b e r [ t p I d x ] + + ;  
 	 	 	 d o u b l e   q u e r y _ p t [ 3 ]   =   {   p t D a n g e r [ i ] . x ,   p t D a n g e r [ i ] . y ,   p t D a n g e r [ i ] . z   } ;  
  
 	 	 	 c o n s t   s i z e _ t   n u m _ r e s u l t s   =   1 ;  
 	 	 	 s i z e _ t   r e t _ i n d e x ;  
 	 	 	 d o u b l e   o u t _ d i s t _ s q r ;  
 	 	 	 K N N R e s u l t S e t < d o u b l e >   r e s u l t S e t ( n u m _ r e s u l t s ) ;  
 	 	 	 r e s u l t S e t . i n i t ( & r e t _ i n d e x ,   & o u t _ d i s t _ s q r ) ;  
 	 	 	 t r e e L i n e I n d e x . f i n d N e i g h b o r s ( r e s u l t S e t ,   & q u e r y _ p t [ 0 ] ,   S e a r c h P a r a m s ( 1 0 ) ) ;  
 	 	 	 i f   ( o u t _ d i s t _ s q r   <   d i s T y p e [ t p I d x ] )   i d x T y p e [ t p I d x ]   =   i ;  
 	 	 }  
  
 	 	 / / g e t   r e p r e s e n t   d a n g e r   p o i n t s  
 	 	 / / s t d : : f o r _ e a c h ( t y p e P n t N u m b e r [ 0 ] ,   t y p e P n t N u m b e r [ s e g N u m b e r   -   1 ] ,   [ & p n t I d x ,   & c i d x ,   l i n e I d x ] ( i n t   n )   { i f   ( n   >   5 )   {   p n t I d x . p u s h _ b a c k ( l i n e I d x [ c i d x ] ) ;   } c i d x + + ;   } ) ;  
 	 	 f o r   ( i n t   i   =   0 ;   i   <   s e g N u m b e r ;   + + i )  
 	 	 {  
 	 	 	 i f   ( t y p e P n t N u m b e r [ i ]   >   5 )   {   p n t I d x . p u s h _ b a c k ( l i n e I d x [ i d x T y p e [ i ] ] ) ;   }  
 	 	 }  
  
 	 	 d e l e t e [ ] t y p e ;   t y p e   =   n u l l p t r ;  
 	 }  
 	 c a t c h   ( b a d _ a l l o c   e )  
 	 {  
 	 	 p r i n t f ( " % s \ n " ,   e . w h a t ( ) ) ;  
 	 	 r e t u r n   - 1 ;  
 	 }  
 	 r e t u r n   0 ;  
 }  
  
 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
 f l o a t   L A S F a l l i n g T r e e s D a n g e r P o i n t s : : L A S D a n g e r P o i n t s _ E l e v a t i o n ( f l o a t   * d a t a I m g ,   i n t   x s i z e ,   i n t   y s i z e ,   d o u b l e   * a d f G e o T r a n s ,  
 	 f l o a t   g x ,   f l o a t   g y )   {  
 	 d o u b l e   d T e m p   =   a d f G e o T r a n s [ 1 ]   *   a d f G e o T r a n s [ 5 ]   -   a d f G e o T r a n s [ 2 ]   *   a d f G e o T r a n s [ 4 ] ;  
 	 i n t   X p i x e l   =   ( a d f G e o T r a n s [ 5 ]   *   ( g x   -   a d f G e o T r a n s [ 0 ] )   -   a d f G e o T r a n s [ 2 ]   *   ( g y   -   a d f G e o T r a n s [ 3 ] ) )   /   d T e m p   +   0 . 5 ;  
 	 i n t   Y l i n e   =   ( a d f G e o T r a n s [ 1 ]   *   ( g y   -   a d f G e o T r a n s [ 3 ] )   -   a d f G e o T r a n s [ 4 ]   *   ( g x   -   a d f G e o T r a n s [ 0 ] ) )   /   d T e m p   +   0 . 5 ;  
 	 i f   ( X p i x e l > x s i z e   | |   X p i x e l < 0   | |   Y l i n e > y s i z e   | |   Y l i n e < 0 )  
 	 	 r e t u r n   - 9 9 9 9 ;  
 	 e l s e  
 	 	 r e t u r n   d a t a I m g [ Y l i n e * x s i z e   +   X p i x e l ] ;  
  
 }  
  
 l o n g   L A S F a l l i n g T r e e s D a n g e r P o i n t s : : L A S D a n g e r P o i n t s _ F a l l i n g T r e e ( f l o a t *   d i s t a n c e ,   i n t   d a n g e r S e c t i o n N u m b e r ,   c o n s t   c h a r *   p a t h D E M ,   I L A S D a t a s e t *   d a t a s e t L i n e ,   I L A S D a t a s e t *   d a t a s e t V e g t e r a i n )   {  
 	 i n t   r s   =   0 ;  
 	 i n t   n u m L i n e R e c t s   =   d a t a s e t L i n e - > m _ n u m R e c t a n g l e s ;  
 	 / / d e m   d a t a s e t  
 	 G D A L A l l R e g i s t e r ( ) ;  
 	 G D A L D a t a s e t H   d a t a s e t   =   G D A L O p e n ( p a t h D E M ,   G A _ R e a d O n l y ) ;  
 	 i n t   x s i z e   =   G D A L G e t R a s t e r X S i z e ( d a t a s e t ) ;  
 	 i n t   y s i z e   =   G D A L G e t R a s t e r Y S i z e ( d a t a s e t ) ;  
 	 f l o a t *   d a t a D E M   =   n e w   f l o a t [ x s i z e * y s i z e ] ;  
 	 G D A L R a s t e r I O ( G D A L G e t R a s t e r B a n d ( d a t a s e t ,   1 ) ,   G F _ R e a d ,   0 ,   0 ,   x s i z e ,   y s i z e ,   d a t a D E M ,   x s i z e ,   y s i z e ,   G D T _ F l o a t 3 2 ,   0 ,   0 ) ;  
 	 d o u b l e   a d f G e o t r a n s f o r m [ 6 ] ;  
 	 G D A L G e t G e o T r a n s f o r m ( d a t a s e t ,   a d f G e o t r a n s f o r m ) ;  
  
 	 f o r   ( i n t   i   =   0 ;   i < n u m L i n e R e c t s ;   + + i )  
 	 {  
 	 	 i n t   n u m P n t I n R e c t   =   d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s _ n u m b e r s ;  
 	 	 f o r   ( i n t   j   =   0 ;   j < n u m P n t I n R e c t ;   + + j )  
 	 	 {  
 	 	 	 p r i n t f ( " \ r % d - % d " ,   n u m P n t I n R e c t ,   j ) ;  
 	 	 	 c o n s t   P o i n t 3 D   l i n e P n t   =   d a t a s e t L i n e - > m _ l a s R e c t a n g l e s [ i ] . m _ l a s P o i n t s [ j ] . m _ v e c 3 d ;  
 	 	 	 r s   =   r s   |   L A S D a n g e r P o i n t s _ F l l i n g T r e e _ P r e P o i n t ( d i s t a n c e ,   d a n g e r S e c t i o n N u m b e r ,   d a t a D E M ,   x s i z e ,   y s i z e ,   a d f G e o t r a n s f o r m ,   & l i n e P n t ,   d a t a s e t V e g t e r a i n ) ;  
 	 	 }  
 	 	 p r i n t f ( " \ n " ) ;  
 	 }  
 	 d e l e t e [ ] d a t a D E M ;   d a t a D E M   =   n u l l p t r ;  
 	 r e t u r n   r s ;  
 }  
  
 l o n g   L A S F a l l i n g T r e e s D a n g e r P o i n t s : : L A S D a n g e r P o i n t s _ F l l i n g T r e e _ P r e P o i n t ( f l o a t *   d i s t a n c e ,   i n t   d a n g e r S e c t i o n N u m b e r ,    
 	 f l o a t   * d e m D a t a ,   i n t   x s i z e ,   i n t   y s i z e , d o u b l e   * a d f G e o t r a n s ,   c o n s t   P o i n t 3 D *   p n t ,   I L A S D a t a s e t *   d a t a s e t V e g t e r i a n )    
 {  
 	 v e c t o r < i n t >   r e c t R a n g e I d x ;  
 	 L A S D a n g e r P o i n t s _ R a n g e ( p n t ,   3   *   d i s t a n c e [ d a n g e r S e c t i o n N u m b e r   -   1 ] ,   d a t a s e t V e g t e r i a n ,   r e c t R a n g e I d x ) ;  
 	 i f   ( d a n g e r S e c t i o n N u m b e r   ! =   3 )  
 	 {  
 	 	 p r i n t f ( " p l z   i n p u t   3   n u m b e r   r a n g e \ n " ) ;  
 	 	 r e t u r n   - 1 ;  
 	 }  
 	 P o i n t 3 D   p n t G r o u n d ;  
 	 p n t G r o u n d . x   =   p n t - > x ;  
 	 p n t G r o u n d . y   =   p n t - > y ;  
 	 p n t G r o u n d . z   =   L A S D a n g e r P o i n t s _ E l e v a t i o n ( d e m D a t a ,   x s i z e ,   y s i z e ,   a d f G e o t r a n s ,   p n t - > x ,   p n t - > y ) ;  
 	 d o u b l e   h e i g h t   =   f a b s ( p n t G r o u n d . z   -   p n t - > z ) ;  
  
 	 / / o n l y   c o n s i d e r   3   t y p e   o f   c l a s s e s  
 	 f o r   ( i n t   i   =   0 ;   i < r e c t R a n g e I d x . s i z e ( ) ;   + + i )  
 	 {  
 	 	 i n t   i n d   =   r e c t R a n g e I d x [ i ] ;  
 	 	 f o r   ( i n t   j   =   0 ;   j   < d a t a s e t V e g t e r i a n - > m _ l a s R e c t a n g l e s [ i n d ] . m _ l a s P o i n t s _ n u m b e r s ;   + + j )   {  
 	 	 	 L A S P o i n t   & l a s p n t   =   d a t a s e t V e g t e r i a n - > m _ l a s R e c t a n g l e s [ i n d ] . m _ l a s P o i n t s [ j ] ;  
 	 	 	 c o n s t   P o i n t 3 D   t m p P n t   =   l a s p n t . m _ v e c 3 d ;  
 	 	 	 i n t   c l a s s T y p e   =   l a s p n t . m _ c l a s s i f y ;  
 	 	 	 i f   ( c l a s s T y p e   = =   e l c D a n g e r )  
 	 	 	 	 c o n t i n u e ;  
  
 	 	 	 i f   ( c l a s s T y p e > e l c F a l l i n g T r e e & & c l a s s T y p e < e l c F a l l i n g T r e e E n d )  
 	 	 	 {  
 	 	 	 	 i f   ( p n t G r o u n d . D i s t a n c e ( t m p P n t )   -   h e i g h t < d i s t a n c e [ 0 ]   & &   c l a s s T y p e > e l c F a l l i n g T r e e L e v e l 1   +   1 )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c F a l l i n g T r e e L e v e l 1 ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   2 5 5 ,   0 ,   0 ) ;  
 	 	 	 	 }  
 	 	 	 	 e l s e   i f   ( p n t - > D i s t a n c e ( t m p P n t )   -   h e i g h t < d i s t a n c e [ 1 ]   & &   c l a s s T y p e > e l c F a l l i n g T r e e L e v e l 2   +   2 )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c F a l l i n g T r e e L e v e l 2 ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   2 5 5 ,   2 5 5 ,   0 ) ;  
 	 	 	 	 }  
 	 	 	 	 e l s e   i f   ( p n t - > D i s t a n c e ( t m p P n t )   -   h e i g h t < d i s t a n c e [ 2 ]   & &   c l a s s T y p e > e l c F a l l i n g T r e e L e v e l 3   +   3 )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c F a l l i n g T r e e L e v e l 3 ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   0 ,   0 ,   2 5 5 ) ;  
 	 	 	 	 }  
 	 	 	 }  
 	 	 	 e l s e  
 	 	 	 {  
 	 	 	 	 i f   ( p n t G r o u n d . D i s t a n c e ( t m p P n t )   -   h e i g h t < d i s t a n c e [ 0 ]   & &   c l a s s T y p e > e l c F a l l i n g T r e e L e v e l 1   +   1 )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c F a l l i n g T r e e L e v e l 1 ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   2 5 5 ,   0 ,   0 ) ;  
 	 	 	 	 }  
 	 	 	 	 e l s e   i f   ( p n t - > D i s t a n c e ( t m p P n t )   -   h e i g h t < d i s t a n c e [ 1 ]   & &   c l a s s T y p e > e l c F a l l i n g T r e e L e v e l 2   +   2 )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c F a l l i n g T r e e L e v e l 2 ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   2 5 5 ,   2 5 5 ,   0 ) ;  
 	 	 	 	 }  
 	 	 	 	 e l s e   i f   ( p n t - > D i s t a n c e ( t m p P n t )   -   h e i g h t < d i s t a n c e [ 2 ]   & &   c l a s s T y p e > e l c F a l l i n g T r e e L e v e l 3   +   3 )  
 	 	 	 	 {  
 	 	 	 	 	 l a s p n t . m _ c l a s s i f y   =   e l c F a l l i n g T r e e L e v e l 3 ;  
 	 	 	 	 	 S e t P o i n t C o l o r ( l a s p n t ,   0 ,   0 ,   2 5 5 ) ;  
 	 	 	 	 }  
 	 	 	 }  
 	 	 }  
 	 }  
 	 r e t u r n   0 ;  
 }  
  
 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
 l o n g   L A S D a n g e r P o i n t s M e r g e A r r g e g a t e : : L A S D a n g e r T e s t F l a n n ( )  
 {  
 	 s t d : : v e c t o r < P o i n t 3 D >   p n t C l o u d ;  
 	 s r a n d ( t i m e ( N U L L ) ) ;  
 	 / / g e n e r a t e d   p n t   c l o u d  
 	 p n t C l o u d . r e s i z e ( 1 0 0 0 0 ) ;  
 	 f o r   ( s i z e _ t   i   =   0 ;   i   <   1 0 0 0 0 ;   i + + )  
 	 {  
 	 	 p n t C l o u d [ i ] . x   =   1 0   *   ( r a n d ( )   %   1 0 0 0 )   /   d o u b l e ( 1 0 0 0 ) ;  
 	 	 p n t C l o u d [ i ] . y   =   1 0   *   ( r a n d ( )   %   1 0 0 0 )   /   d o u b l e ( 1 0 0 0 ) ;  
 	 	 p n t C l o u d [ i ] . z   =   1 0   *   ( r a n d ( )   %   1 0 0 0 )   /   d o u b l e ( 1 0 0 0 ) ;  
 	 }  
  
 	 t y p e d e f   P o i n t C l o u d A d a p t o r < s t d : : v e c t o r < P o i n t 3 D > >   P C A d a p t o r ;  
 	 c o n s t   P C A d a p t o r   p c A d a p t o r P n t s ( p n t C l o u d ) ;  
  
 	 / / t y p e d e f   K D T r e e S i n g l e I n d e x A d a p t o r < L 2 _ S i m p l e _ A d a p t o r < d o u b l e ,   P C A d a p t o r > ,   P C A d a p t o r ,   3 >   k d _ t r e e ;  
 	 k d _ t r e e   t r e e I n d e x ( 3 ,   p c A d a p t o r P n t s ,   K D T r e e S i n g l e I n d e x A d a p t o r P a r a m s ( 1 0 ) ) ;  
 	 t r e e I n d e x . b u i l d I n d e x ( ) ;  
  
 	 / /   d o   a   k n n   s e a r c h  
 	 d o u b l e   q u e r y _ p t [ 3 ]   =   {   0 . 5 ,   0 . 5 ,   0 . 5   } ;  
 	 c o n s t   s i z e _ t   n u m _ r e s u l t s   =   1 0 ;  
 	 s i z e _ t   r e t _ i n d e x [ 1 0 ] ;  
 	 d o u b l e   o u t _ d i s t _ s q r [ 1 0 ] ;  
 	 / / K N N R e s u l t S e t < d o u b l e >   r e s u l t S e t ( n u m _ r e s u l t s ) ;  
 	 c o n s t   d o u b l e   r a d i u s   =   1 0 ;  
 	 s t d : : v e c t o r < s t d : : p a i r < s i z e _ t ,   d o u b l e >   >   i n d i c e s _ d i s t s ;  
 	 R a d i u s R e s u l t S e t < d o u b l e ,   s i z e _ t >   r e s u l t S e t ( r a d i u s ,   i n d i c e s _ d i s t s ) ;  
  
 	 / / r e s u l t S e t . i n i t ( r e t _ i n d e x ,   o u t _ d i s t _ s q r ) ;  
 	 t r e e I n d e x . f i n d N e i g h b o r s ( r e s u l t S e t ,   & q u e r y _ p t [ 0 ] ,   S e a r c h P a r a m s ( ) ) ;  
  
 	 / / i n d e x . k n n S e a r c h ( q u e r y ,   i n d i c e s ,   d i s t s ,   n u m _ r e s u l t s ,   m r p t _ f l a n n : : S e a r c h P a r a m s ( 1 0 ) ) ;  
 	  
 	 / / p r i n t f ( " k n n S e a r c h ( n n = % d ) \ n " ,   n u m _ r e s u l t s ) ;  
  
 	 f o r   ( i n t   i   =   0 ;   i   <   r e s u l t S e t . m _ i n d i c e s _ d i s t s . s i z e ( ) ; + + i )  
 	 {  
 	 	 p r i n t f ( " r e t _ i n d e x = % d   o u t _ d i s t _ s q r = % l f \ n " ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . f i r s t ,   r e s u l t S e t . m _ i n d i c e s _ d i s t s [ i ] . s e c o n d ) ;  
 	 }  
  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s M e r g e A r r g e g a t e : : L A S D a n g e r E x t r a c t ( I L A S D a t a s e t *   l a s D a t a s e t ,   P o i n t 3 D s   & d a n g e r P n t s )  
 {  
 	 i n t   p o i n t s N u m b e r   =   l a s D a t a s e t - > m _ t o t a l R e a d L a s N u m b e r ;  
 	 d a n g e r P n t s . c l e a r ( ) ;  
 	 t r y  
 	 {  
 	 	 d a n g e r P n t s . r e s e r v e ( p o i n t s N u m b e r * 0 . 1 ) ;  
  
 	 	 f o r   ( i n t   i   =   0 ;   i   <   p o i n t s N u m b e r ;   + + i )  
 	 	 {  
 	 	 	 L A S I n d e x   i d x L a s   =   l a s D a t a s e t - > m _ L A S P o i n t I D [ i ] ;  
 	 	 	 c o n s t   L A S P o i n t   & l a s P n t   =   l a s D a t a s e t - > m _ l a s R e c t a n g l e s [ i d x L a s . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ i d x L a s . p o i n t _ i d x _ i n R e c t ] ;  
 	 	 	 i f ( l a s P n t . m _ c l a s s i f y = = 3 2 )  
 	 	 	 	 d a n g e r P n t s . p u s h _ b a c k ( l a s P n t . m _ v e c 3 d ) ;  
 	 	 }  
 	 }  
 	 c a t c h   ( b a d _ a l l o c   e )  
 	 {  
 	 	 p r i n t f ( e . w h a t ( ) ) ;  
 	 }  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s M e r g e A r r g e g a t e : : L A S D a n g e r E x t r a c t L i n e P o i n t s ( I L A S D a t a s e t   * l i n e D a t a s e t ,  
 	 P o i n t 3 D s   d a n g e r P n t s ,   P o i n t 3 D s   & l i n e P n t s )  
 {  
 	 / / � � � � � � � � � �  
 	 c o n s t   P C A d a p t o r   p c A d a p t o r P n t s ( d a n g e r P n t s ) ;  
 	 k d _ t r e e   t r e e I n d e x ( 3 ,   p c A d a p t o r P n t s ,   K D T r e e S i n g l e I n d e x A d a p t o r P a r a m s ( 1 0 ) ) ;  
 	 t r e e I n d e x . b u i l d I n d e x ( ) ;  
 	 c o n s t   s i z e _ t   n u m _ r e s u l t s   =   1 ;  
 	 s i z e _ t   r e t _ i n d e x ;  
 	 d o u b l e   o u t _ d i s t _ s q r ;  
 	 l i n e P n t s . r e s i z e ( d a n g e r P n t s . s i z e ( ) ) ;  
  
 	 f o r   ( i n t   i   =   0 ;   i   <   l i n e D a t a s e t - > m _ t o t a l R e a d L a s N u m b e r ;   + + i )  
 	 {  
 	 	 c o n s t   L A S I n d e x   & l a s I d x   =   l i n e D a t a s e t - > m _ L A S P o i n t I D [ i ] ;  
  
 	 	 d o u b l e   q u e r y _ p t [ 3 ]   =   {    
 	 	 	 l i n e D a t a s e t - > m _ l a s R e c t a n g l e s [ l a s I d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ l a s I d x . p o i n t _ i d x _ i n R e c t ] . m _ v e c 3 d . x   ,  
 	 	 	 l i n e D a t a s e t - > m _ l a s R e c t a n g l e s [ l a s I d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ l a s I d x . p o i n t _ i d x _ i n R e c t ] . m _ v e c 3 d . y ,  
 	 	 	 l i n e D a t a s e t - > m _ l a s R e c t a n g l e s [ l a s I d x . r e c t a n g l e _ i d x ] . m _ l a s P o i n t s [ l a s I d x . p o i n t _ i d x _ i n R e c t ] . m _ v e c 3 d . z  
 	 	 } ;  
 	 	 K N N R e s u l t S e t < d o u b l e >   r e s u l t S e t ( n u m _ r e s u l t s ) ;  
 	 	 r e s u l t S e t . i n i t ( & r e t _ i n d e x ,   & o u t _ d i s t _ s q r ) ;  
 	 	 t r e e I n d e x . f i n d N e i g h b o r s ( r e s u l t S e t ,   & q u e r y _ p t [ 0 ] , S e a r c h P a r a m s ( 1 0 ) ) ;  
  
 	 	 l i n e P n t s [ r e t _ i n d e x ] . x   =   q u e r y _ p t [ 0 ] ;  
 	 	 l i n e P n t s [ r e t _ i n d e x ] . y   =   q u e r y _ p t [ 1 ] ;  
 	 	 l i n e P n t s [ r e t _ i n d e x ] . z   =   q u e r y _ p t [ 2 ] ;  
 	 }  
  
 	 r e t u r n   0 ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s M e r g e A r r g e g a t e : : L A S D a n g e r A g g r e g a t e ( P o i n t 3 D s   d a n g e r P n t s ,   i n t   * t y p e ,   f l o a t   k n n R a n g e )  
 {  
 	 L a s A l g o r i t h m : : P o i n t C l o u d S e g m e n t   s e g m e n t A l g ;  
 	 r e t u r n   s e g m e n t A l g . P o i n t C l o u d S e g m e n t _ D B S c a n ( d a n g e r P n t s ,   t y p e ,   k n n R a n g e ) ;  
 }  
  
 l o n g   L A S D a n g e r P o i n t s M e r g e A r r g e g a t e : : L A S D a n g e r M e r g e ( P o i n t 3 D s   d a n g e r P n t s ,   i n t   * t y p e ,   i n t   t y p e N u m b e r s ,  
 	 P o i n t 3 D s   l i n e P n t s ,   i n t   * c o r r e s p o n d P a i r s )  
 {  
 	 i n t   n u m b e r P n t s   =   d a n g e r P n t s . s i z e ( ) ;  
 	 d o u b l e   * d i s t a n c e   =   n e w   d o u b l e [ t y p e N u m b e r s ] ;  
 	 f o r   ( i n t   i   =   0 ;   i   <   t y p e N u m b e r s ;   + + i )  
 	 {  
 	 	 d i s t a n c e [ i ]   =   _ M A X _ L I M I T _ ; / / � � � � � �  
 	 	 c o r r e s p o n d P a i r s [ i ]   =   0 ;  
 	 }  
 	 f o r   ( i n t   i   =   0 ;   i   <   n u m b e r P n t s ;   + + i )  
 	 {  
 	 	 i n t   i d x   =   t y p e [ i ] ;  
 	 	 d o u b l e   d i s   =   d a n g e r P n t s [ i ] . D i s t a n c e ( l i n e P n t s [ i ] ) ;  
 	 	 i f   ( d i s   <   d i s t a n c e [ i d x ] )  
 	 	 {  
 	 	 	 d i s t a n c e [ i d x ]   =   d i s ;  
 	 	 	 c o r r e s p o n d P a i r s [ i d x ]   =   i ;  
 	 	 }  
 	 }  
  
 	 d e l e t e [ ] d i s t a n c e ;   d i s t a n c e   =   n u l l p t r ;  
 	 r e t u r n   0 ;  
 }