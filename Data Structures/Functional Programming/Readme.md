<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#what-is-functional-programming">What is Functional Programming?</a></li>
    <li><a href="#imperative-vs-declarative">Imperative vs Declarative</a></li>
    <li><a href="#four-principles">Four Principles of FP</a></li>
    <li><a href="#pure-functions-side-effects">Pure Functions & Side Effects</a></li>
    <li><a href="#higher-order-functions">Higher-Order Functions</a></li>
    <li><a href="#closures-currying">Closures & Currying</a></li>
    <li><a href="#pipe-compose">Pipe & Compose</a></li>
  </ol>
</details>

<hr />

<h2 id="what-is-functional-programming">What is Functional Programming?</h2>
<ul>
  <li>A programming style where computation is done by applying <strong>functions</strong> to data.</li>
  <li>Focus on <strong>what</strong> to compute (expressions), not <strong>how</strong> (steps).</li>
  <li>Emphasizes predictability, safety, and modularity.</li>
</ul>

<h2 id="imperative-vs-declarative">Imperative vs Declarative</h2>
<ul>
  <li><strong>Imperative</strong>: tells <em>how</em> to do something (steps, loops, state changes).</li>
  <li><strong>Declarative</strong>: tells <em>what</em> you want (lets system handle steps).</li>
  <li>FP is mostly <strong>declarative</strong> (e.g., using <code>map</code> instead of loops).</li>
</ul>

<h2 id="four-principles">Four Principles of FP</h2>
<ol>
  <li><strong>Predictable</strong> – output depends only on input.</li>
  <li><strong>Safe</strong> – avoids uncontrolled side effects & shared mutable state.</li>
  <li><strong>Referentially Transparent</strong> – expressions can be replaced with their values safely.</li>
  <li><strong>Modular</strong> – programs built from small, reusable functions.</li>
</ol>

<h2 id="pure-functions-side-effects">Pure Functions & Side Effects</h2>
<h3>Pure Functions</h3>
<ul>
  <li>Depend only on arguments.</li>
  <li>No side effects (no mutation, no I/O).</li>
  <li>Same input → same output.</li>
</ul>

<h3>Side Effects</h3>
<ul>
  <li>Changes to system state or external interaction.</li>
  <li>Examples: modifying variables, printing, logging, DB/file writes, user input.</li>
  <li>FP tries to <strong>control/limit</strong> side effects.</li>
</ul>

<h3>Why Pure Functions Matter</h3>
<ul>
  <li><strong>Cacheable</strong> (memoized).</li>
  <li><strong>Testable</strong> (input → output).</li>
  <li><strong>Portable</strong> (self-contained).</li>
  <li><strong>Parallel-friendly</strong> (no shared state).</li>
</ul>

<h2 id="higher-order-functions">Higher-Order Functions</h2>
<p>A <strong>higher-order function</strong> takes a function as input or returns a function.</p>

<ul>
  <li><strong>map</strong>: apply a function to each item → new list, same size.</li>
  <li><strong>filter</strong>: keep only items where a predicate is true.</li>
  <li><strong>reduce</strong>: combine items into a single value.</li>
</ul>

<h2 id="closures-currying">Closures & Currying</h2>
<h3>Closure</h3>
<ul>
  <li>A function that <strong>remembers</strong> variables from its outer scope.</li>
</ul>

<h3>Currying</h3>
<ul>
  <li>Breaks a multi-argument function into chained single-argument functions.</li>
  <li>Allows <strong>partial application</strong> of arguments.</li>
  <li>Works because of closures.</li>
</ul>

<h2 id="pipe-compose">Pipe & Compose</h2>
<ul>
  <li><strong>pipe(f, g, h)</strong>: runs functions <strong>left → right</strong> (f → g → h).</li>
  <li><strong>compose(f, g, h)</strong>: runs functions <strong>right → left</strong> (h → g → f).</li>
  <li>Both return a <strong>new function</strong> that chains operations together.</li>
</ul>
