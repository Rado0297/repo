#lang racket

(define (member? x xs)
  (if (null? xs)
      #f
      (if (= x (car xs))
          #t
          (member? x (cdr xs))
      )
  )
)

(define (findUnique xs)
  (if (null? xs)
      '()
      (if (member? (car xs) (cdr xs))
          (findUnique (filter (lambda (x) (if (= (car xs) x) #f #t)) xs))
          (cons (car xs) (findUnique (cdr xs)))
      )
   )
)

(define (maxUnique ll)
  (apply max (findUnique ll))
)