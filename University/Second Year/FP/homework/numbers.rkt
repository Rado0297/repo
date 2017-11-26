#lang racket
(require rackunit)
(require rackunit/text-ui)

; Искаме да дефинираме следните имена

; one, two, three, four, five, six, seven, eight, nine, ten
; plus, minus, times, div

; Така че тестовете долу да минават.

(define (one . params)
  (if (null? params)
      1
      ((car (car params)) 1 (car (cdr (car params))))
  )
)

(define (two . params)
  (if (null? params)
      2
      ((car (car params)) 2 (car (cdr (car params))))
  )
)

(define (three . params)
  (if (null? params)
      3
      ((car (car params)) 3 (car (cdr (car params))))
  )
)

(define (four . params)
  (if (null? params)
      4
      ((car (car params)) 4 (car (cdr (car params))))
  )
)

(define (five . params)
  (if (null? params)
      5
      ((car (car params)) 5 (car (cdr (car params))))
  )
)

(define (six . params)
  (if (null? params)
      6
      ((car (car params)) 6 (car (cdr (car params))))
  )
)

(define (seven . params)
  (if (null? params)
      7
      ((car (car params)) 7 (car (cdr (car params))))
  )
)

(define (eight . params)
  (if (null? params)
      8
      ((car (car params)) 8 (car (cdr (car params))))
  )
)

(define (nine . params)
  (if (null? params)
      9
      ((car (car params)) 9 (car (cdr (car params))))
  )
)

(define (ten . params)
  (if (null? params)
      10
      ((car (car params)) 10 (car (cdr (car params))))
  )
)

(define (plus x)
  (list + x)
)

(define (minus x)
  (list - x)
)

(define (times x)
  (list * x)
)

(define (div x)
  (list / x)
)

(define tests
  (test-suite "Numbers tests"
    (check-equal? (one (plus (one))) 2)
    (check-equal? (three (times (five))) 15)
    (check-equal? (eight (div (two))) 4)
    (check-equal? (seven (times (six))) 42)
    (check-equal? (nine (minus (three))) 6)
    ; Добави и за изваждане
  )
)

(run-tests tests 'verbose)