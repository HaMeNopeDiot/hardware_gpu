#let line_margin = 1.5em

#let template(doc) = {
  let in-ref = state("in-ref", false)
  show ref: it => in-ref.update(true) + it + in-ref.update(false)
  let sup(fig, ref) = (supplement: context if in-ref.get() { ref } else { fig })
  show figure.where(kind: image): set figure(..sup("Рис.", "рис."))
  show figure.where(kind: image): set figure.caption(separator: [. ])
  show figure.where(kind: table): set figure(..sup("Таблица", "табл."))
  show figure.where(kind: table): set figure.caption(position: top, separator: [. ])
  show figure.caption.where(kind: table): set align(right)
  show figure.where(kind: raw): set figure(..sup("Листинг", "лист."))
  show figure.where(kind: raw): set figure.caption(separator: [. ])
  show raw: set text(font: "New Computer Modern", size: 14pt)
  show figure: set block(breakable: true)
  show heading: set align(center)
  show heading: set block(below: line_margin)
  show heading.where(level: 2): it => {text(style: "italic", weight: "bold", it)}
  show heading.where(level: 3): it => {align(left, text(style: "italic", weight: "regular", it))}
  show heading.where(level: 4): it => {align(left, text(style: "italic", weight: "regular", it))}
  show heading.where(level: 5): it => {align(left, text(style: "italic", weight: "regular", it))}
  show heading.where(level: 6): it => {align(left, text(style: "italic", weight: "regular", it))}
  show heading.where(level: 7): it => {align(left, text(style: "italic", weight: "regular", it))}
  doc
}

#show: template

#set text(
    font: "New Computer Modern",
    size: 14pt,
    lang: "ru",
    hyphenate: false
)
#set math.equation(numbering: "(1)")

#set par(
    justify: true,
    first-line-indent: (
        amount: 1.25cm,
        all: true,
    ),
    spacing: line_margin,
    leading: line_margin,
)

#set heading(numbering: "1.")

#include "title.typ"

#set page(
  header: context [
    #set align(center)
    #counter(page).display("1")
  ],
  margin: (
    top: 2cm,
    bottom: 2cm,
    right: 1.5cm,
    left: 3cm,
  ),
)

#outline(
  title: [Содержание]
)

#pagebreak()

#include "intro.typ"
#pagebreak()
#include "contents.typ"
#pagebreak()
#set heading(numbering: none)
#include "conclusion.typ"
#pagebreak()
#include "literature.typ"
#pagebreak()
#include "appendix.typ"
