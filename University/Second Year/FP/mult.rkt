#lang racket
(define (f x y)
  (if (= y 0)
      0
      (+
       x
       (f x (- y 1))
      )
  )
)