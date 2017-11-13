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
  (void)
)

(display "ACTUAL TESTS-----------------------------------------------------------\n")
(run-tests map-tests 'verbose)
(run-tests filter-tests 'verbose)