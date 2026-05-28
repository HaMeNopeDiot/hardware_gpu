#let line_margin = 1.15em

#let template(doc) = {
  let in-ref = state("in-ref", false)
  show ref: it => in-ref.update(true) + it + in-ref.update(false)
  let sup(fig, ref) = (supplement: context if in-ref.get() { ref } else { fig })
  show figure.where(kind: image): set figure(..sup("Рис.", "рис."))
  show figure.where(kind: image): set figure.caption(separator: [ --- ])
  show figure.where(kind: table): set figure(..sup("Таблица", "табл."))
  show figure.where(kind: table): set figure.caption(position: top, separator: [ --- ])
  show figure.caption.where(kind: table): set align(left)
  show figure.where(kind: raw): set figure(..sup("Листинг", "лист."))
  show figure.where(kind: raw): set figure.caption(separator: [ --- ])
  show raw: set text(
    font: "New Computer Modern",
    size: 14pt,
  )
  show figure: set block(breakable: true)
  show heading: set block(below: line_margin)

  doc
}

#show: template

#set text(
    font: "New Computer Modern",
    size: 14pt,
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
#set text(lang: "ru")

#include "title.typ"

#set page(
  margin: (
    top: 2.2cm,
    bottom: 2.2cm,
    right: 1cm,
    left: 3cm,
  ),
  numbering: "1",
)

#outline(
  title: [Содержание]
)

#pagebreak()

#include "intro.typ"
#pagebreak()
#include "contents.typ"
#pagebreak()
#include "conclusion.typ"

#pagebreak()
#include "literature.typ"
