#lang racket
(require rackunit)
(require rackunit/text-ui)
(require "map.rkt")
(require "filter.rkt")
(require "fold-left.rkt")
(require "fold-right.rkt")

; Дефинирайте filter въз основа на fold-right
(define (filter p? xs)
  (void)
)

; Дефинирайте map въз основа на fold-left
(define (map f xs)
  (if (null? xs) '()
      (fold-left f (f 0 (car xs)) (cdr xs))
  )

  ;(define (map f xs)
 ;   (if (null? xs) '()
   ;     (cons (f (car xs)) (map f (cdr xs)))
    ;    )
  ;)

  ;(define (fold-left op null-value xs)
   ; (if (null? xs) null-value
    ;    (fold-left op (op null-value (car xs)) (cdr xs))
     ;   )
    ;)

  ; При добро желание, може да го накараме да прави рекурсивен процес:
  ;(define (fold-left-rec op null-value xs)
   ; (if (null? xs) null-value
    ;    (op (fold-left-rec op null-value (cdr xs)) (car xs))
     ;   )
  ;)

  
)

(display "ACTUAL TESTS-----------------------------------------------------------\n")
(run-tests map-tests 'verbose)
(run-tests filter-tests 'verbose)