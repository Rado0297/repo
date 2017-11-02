#lang racket
(define input 0)

(define (fact input)
  (if (= input 1)
      1
      (* input (fact (- input 1)))
  )
)