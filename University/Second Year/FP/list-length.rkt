#lang racket
(require rackunit)
(require rackunit/text-ui)

; Търсим дължината на даден списък.
(define (len-helper xs res)
  (if (null? xs) res
      (len-helper (cdr xs) (+ 1 res)))
)

(define (length xs)
  (len-helper xs 0)
)

(define tests
  (test-suite "dummy tests"
    (check-equal? (length '()) 0)
    (check-equal? (length '(1 2)) 2)
    (check-equal? (length '(3 2 1 2 3 9 3 #f)) 8)
  )
)

(run-tests tests 'verbose)