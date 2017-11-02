#lang racket
(require rackunit)
(require rackunit/text-ui)

; Искаме да вземем i-тия елемент от списъка lst, като броим от 0.

(define (helper list i start)
  (if (= i start) (car list)
      (helper (cdr list) i (+ 1 start))
  )
)

(define (list-ref lst i)
  (helper lst i 0)
)

(define tests
  (test-suite "List ref tests"
    (check-equal? (list-ref '(5 9 2) 0) 5)
    (check-equal? (list-ref '(1 8 6 2 3) 4) 3)
  )
)

(run-tests tests 'verbose)