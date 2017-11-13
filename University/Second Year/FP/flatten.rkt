#lang racket
(require rackunit)
(require rackunit/text-ui)

; Искаме да направим списък от всички стойности в даден такъв.
; Искаме нивата на влагане да изчезнат.

(define (atom? x)
  (and (not (null? x))
       (not (pair? x))))

(define (flatten xs)
  (cond ((null? xs) '())
        ((atom? (car xs)) (cons (car xs) (flatten (cdr xs))))
        (else (append (flatten (car xs)) (flatten (cdr xs))))
  )
)

(define tests
  (test-suite "Flatten"
    (check-equal? (flatten '(1 3 ("wow" ("nesting") ("overload" 38 91)))) '(1 3 "wow" "nesting" "overload" 38 91))
    (check-equal? (flatten '(1 2 3)) '(1 2 3))
    (check-equal? (flatten '(((3)))) '(3))
  )
)

(run-tests tests 'verbose)