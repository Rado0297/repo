#lang racket

(define (helper f g a b op)
  (if (= a (+ 1 b))
      #f
      (if (op (f a) (g a))
          #t
          (helper f g (+ 1 a) b op)
      )
  )
)

;(define (mixed? f g a b)
;  (if (= a b)
;      #f
;      (if (< (f a) (g a))
;          (helper f g a b >)
;          (if (> (f a) (g a))
;              (helper f g a b <)
;              (mixed? f g (+ 1 a) b)
;          )
;      )
;  )
;)

(define (mixed? f g a b)
  (if (and (not (null? (filter (lambda(x) (> (f x) (g x))) (range a (+ 1 b))))) (not (null? (filter (lambda(x) (< (f x) (g x))) (range a (+ 1 b))))))
      #t
      #f
      )
)