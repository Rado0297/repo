#lang racket
(require rackunit)
(require rackunit/text-ui)

; Търсим сумата на числата от даден списък

(define (sum-helper xs res)
  (if (null? xs) res
      (sum-helper (cdr xs) (+ res (car xs)))
  )
)

(define (sum-elements xs)
  (sum-helper xs 0)
)

(define tests
  (test-suite "Sum elements tests"
    (check-equal? (sum-elements (range 1 6)) 15)
    (check-equal? (sum-elements '(1 9)) 10)
    (check-equal? (sum-elements '(-2 3 -1)) 0)
  )
)

(run-tests tests 'verbose)