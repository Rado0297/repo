#lang racket
(define (ack m n)
  (cond
    ((= m 0) (+ n 1))
    ((and (> m 0) (= n 0))
             (ack (- m 1) 1)
    )
    ((and (> m 0) (> n 0))
             (ack
              (- m 1)
              (ack m (- n 1))
             )
    )
  )
)