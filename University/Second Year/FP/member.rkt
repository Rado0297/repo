#lang racket
(require rackunit)
(require rackunit/text-ui)

; Искаме да проверим дали х се съдържа в lst

(define (helper list x)
  (if (null? list) #f
      (cond ((= (car list) x) #t)
            (else (helper (cdr list) x))
      )
  )
)

(define (member? x lst)
  (helper lst x)
)

(define tests
  (test-suite "member tests"
    (check-true (member? 2 (range 1 6)))
    (check-false (member? 22 (range 1 20)))
  )
)

(run-tests tests 'verbose)