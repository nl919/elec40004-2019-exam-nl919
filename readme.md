ELEC40004 Final Exam
====================

This is the repository where the final exam will appear,
in sub-directories q1, q2, and q3.

Schedule
------

Start: 10:00 May 4th

Final deadline: 10:00 May 5th

Intended length: 8 hours (inc. 1 hour lunch)

Selected Questions
==================

In your final commit you should check exactly two of these
check-boxes to indicate which questions you have decided
to answer:

- [ ] : Question 1
- [x] : Question 2
- [x] : Question 3

If you do not tick enough boxes, or tick too many, then
Q1 and Q2 will be marked by default.

Note that you are welcome to try all three questions, but
you must select just two for assessment.

Examples of ticked and un-ticked boxes:

- [x] : Ticked (it doesn't matter which character you use)
- [ ] : Un-ticked

Errors in the Exam
==================

If you encounter an error or inconsistency in the exam, you
should attempt to work around it in the most appropriate,
sensible, and consistent way. You should not ask other
teams what their opinion is or try to build a group consensus.

If you encounter any genuine bugs, document them in the file
`errata.md`, and include it in your submission.

Exam timing
===========

You are expected to spend 8 hours on this exam, from your first commit
through to the last commit. You can start whenever you like within
the exam period.

The 8 hour time budget will not be enforced, and is merely a strong
suggestion. During the period you are actively working on it you should
continue to push at regular intervals.

Given the long time period during which the work can be started
and completed, there are no grace-periods, and the 10:00 May 5th
deadline is hard.

Initial clone and push
======================

One of your team should clone this specification, and push it
to your shared repository at `elec40004-2019-exam-${TEAM}` at
`https://github.com/ELEC40004/elec40004-2019-exam-${TEAM}`,
for whatever your value of `${TEAM}` is. It should be of the form
`${LOGIN1}_${LOGIN2}`, and only you and your partner have access
to it.

When this push is detected you are considered to have started,
and snapshots of your pushed repo will be taken at random intervals.

From that point on you should only look at the spec in your
private repository, and should ignore the globally visible spec.
Changes to the globally visible spec may occur while the exam
is running, but these will only ever be related to anti-cheating
measures. In particular:

- The changes will never change the difficulty, scope, or meaning of the questions.
- Any errors contained in the questions will not be addressed or fixed.
- Trying to identify changes between the global spec and your cloned
  spec will never give you any advantage.

Given no-one is going to try to cheat, you can all just clone and
push to your private spec, and from that point on just ignore the
global spec.

Working during the day
======================

During the period you work on it, you should be pushing your
intermediate work at regular intervals - at least every
60 minutes while you are actively working, and ideally more
frequently during the periods your are actively coding and
testing. It is strongly recommended that you push to remote
feature branches rather than merging and pushing to master,
and merge to master only as you complete tasks.

If you don't have any code to commit, then it is a good idea
to push a text file recording what you were doing. This is
also useful for your partner.

Your commit history is your record of what you did and in
what order - it may be considered odd if there was
no activity for four hours, and then suddenly a whole
bunch of perfect code appeared at once. Your development
history should be your actual history, including partially
working code, not-quite-compiling code, test-code, script and
test-case files.

You may wish to take breaks during the day, which is fine.
If you are breaking for an extended period (e.g. an hour
or more), it is recommended that you commit and push before
starting the break. You may also wish to modify and commit
something small when you start up again.

Submission
==========

Your final submission is whatever the last commit is
on master at 10:00 on May 5th.

Where there are inconsistencies in timing, the timing of observed
pushes to github are used - we are well aware that git
timestamps in a repo can be faked in the local histories,
but there is no way to fake the timing with respect to a pull.

Backup submissions via hash can be made through blackboard.
Note that this is only a temporary route to prove that you
completed work at a particular time. Eventually you'll need
to push the corresponding commit into github that matches
that hash, so you **must** keep hold of your local repositories
until you manage to push.

Submission of code via any route other than your github repo will
not be accepted. The blackboard route is only there to allow
submission of a hash, not for submission of a zip file of code.

Your submission consists of the contents of the master branch
in the repo in github. It is strongly suggested that you
clone your submission from github into a fresh
directory and check that you have added all files needed,
and have committed the latest versions.

Assessment
==========

Assessment is via automated tests that probe whether your submission
fulfills the specification. In order to get 100% a submission would
need to pass all tests.

Humans will look at the output of the assessment scripts in order to:

1. Check that the assessment scripts are operating correctly.
2. Investigate any reported errata.
2. Look for minor mistakes that caused large portions of an otherwise
   working solution to fail, and manually fix them in exchange for a penalty.

Errata
------

Any substantial errata which affects a sub-part will mean that the
assessment scripts will be modified or manually adjusted to accept
all reasonable interpretations of the question. Trivial errors which
have an obvious fix (for example, spelling mistake in the text, contradictions
which can be definitively solved) should just be solved.

Manual fixes
------------

Manual fixes during assessment follow these principles:

1. Manual fixes come with an additive marks penalty; in general, a
   solution that needed no fixes should get higher marks than one than did.
   
2. Manual fixes will never result in the marks going down - if the marks
   penalty is greater than the additional benefit, then the fix will
   be removed.

3. Code that would not compile under any reasonable assumptions about
   systems will not be fixed.

4. Code that would crash or fail on any system will not be fixed.

The types of fixes that might be considered might include minor typos
in file names, small mistakes due to system incompatibilities, small
problems due to github mistakes. However, it must be clear that the
code did work on some system at some point - there are no partial
marks for sketches of code that clearly never compiled, or immediately
crash.

Cheating / plagiarism
=====================

The standard requirements on cheating for apply here. Because this
exam contains an applied component over an extended period, the
following are explicitly allowed:

- You can access any _passive_ source of information while you work. Passive
  sources are anything where you only search or look things up, such as
  google searches, looking at lectures notes, watching videos, reading text books,
  accessing documentation, reading pre-existing questions on stack-overflow, and so on.

- You and your partner can use any communication method, tools or
  software that help you to collaborate or solve the problems. Tools and software
  might include maths packages, simulators, debuggers, IDEs, or anything else
  that you directly use and control.

- You are free to talk to family members, partners, friends, and so on during
  the exam period, as long as you don't discuss the exam content.

The college's general policies on academic dishonesty, plagiarism and cheating also apply.

Things that you explicitly can't do are:

- You should not copy code or other content from any other source than the exam specification
  and it's associated code. If at any point you paste more than one word of text into your submission
  and it wasn't copied from somewhere else in your repo, it is probably plagiarism.

- You should not talk to people outside your team about the exam content, including
  coding, algorithms, debugging, suggestions on approaches, or anything else. While
  you can talk to people during the exam period, potentially including other people
  from other teams, you should avoid discussing the content of the exam. 

- You should not use _active_ sources of information, such as posting new questions
  on stack-overflow, discussing things in forums, asking family members or seniors
  for suggestions, and so on. Note that passively observing a conversation where
  others are discussing the exam would also be considered using an active source
  of information.

Cheating counter-measures
-------------------------

A number of active and passive counter-measures will be used to look for
cheating, including both automated and manual checks, and methods used
both during and after the exam.

Nobody will be accused of cheating solely based on automated methods; all
suspicious activity will be manually reviewed, and a compelling case
will be needed before any team is reported to the departmental plagiarism
committee. Some activities may look suspicious but could have a good explanation;
in such cases teams may be contacted to ask them about it and clarify their
submission.

The 8 hour suggested time will not be enforced, but you should be careful
if you are working over very long time periods. Extended debugging
activity would usually result in evidence of extended debugging activity,
with tests being developed, and code being modified/changed. If a bug
is suddenly fixed 1 hour before the deadline, but there has been no
other activity for 8 hours, it might look odd and be queried - however,
such patterns would **not** be considered prima facie evidence of cheating unless
there were also other patterns being noticed.

The easiest way to avoid suspicion of any form of cheating is simply
to commit and push your work in progress regularly, including partial code,
notes, test-scripts, test-data, and so on. We do not have a quota
of cheaters that we expect to find, so if there is zero suspicious
behaviour, we are very happy. We also start from an assumption that
things which look suspicious have an innocent explanation, so are
not looking to catch people out or trap them.




Possible Questions
==================

How do I query errors in the exam?
----------------------------------

You can't. The final exam has been checked to a high-level of detail (much
higher than the example questions), and any remaining errors will be minor.

Based on the various dry runs, quite a few things that people
thought were errors on initial reading were simply things
that they hadn't quite understood, and eventually became clear
as they worked through the questions. So in those case a group
discussion about "is this an error" at the start of the exam
is exactly the same as "does anyone know how we answer this
question?".

It there is a genuine error, then record it in the errata, make
some reasonable assumptions to get round it, and carry on.

Can I check whether I've understood the question correctly?
-----------------------------------------------------------

No - just like a normal exam, understanding the question is part of
the assessment. 

If there is a genuine ambiguity then you should record this in the
errata, identifying which question/task/sub-task and the problem.
Any case where there is a valid interpretation which was not considered
by the exam setter will still be accepted as correct (just like
marking a normal exam).

What happens if we mess up our repo, and lose the history?
----------------------------------------------------------

Your private repo is periodically snapshotted from two different
locations, on at least an hourly basis. Even if you accidentally
did a `git push --force` just before the deadline that deleted
your entire repo, the snapshots would still exist.

If there is no hard 8 hour limit, won't the average marks rise?
---------------------------------------------------------------

Yes, probably. Given the current circumstances, this seems a better
tradeoff than trying to enforce the 8 hour limit precisely. The
mock showed it was technically possible, but it probably isn't
worth the extra stress.

Based on estimations of the competency/ability of the cohort from
mid-terms, labs, and so on, there should still be a good spread. 
Current guess is that the average for the exam might rise to
65-75% (rather than 50-55%), based on the questions and spread
of ability seen.

If the average marks rise, won't the module be moderated down?
--------------------------------------------------------------

Possibly.

There is a [well defined procedure](https://www.imperial.ac.uk/media/imperial-college/faculty-of-engineering/electrical-and-electronic-engineering/public/undergraduate/moderation-of-module-marks.pdf)
for moderating up modules (not exams) up and/or down. In normal
circumstances this would come into play in a mechanical way,
but it may be different this year.

Are the practise questions a good model for the real questions?
---------------------------------------------------------------

Yes, to the extent possible. Some time in Sep 2019 a few people
generated a bunch of question ideas, a sub-set of which were
then turned into questions. Some of those you've already seen as
the 8 practise questions, while 3 of them became the exam.
No particular selection criteria were applied to split them into
practise versus final.

The practise questions were really hard. I could only start 1/3 of them...
-----------------------------------------------------------------------

Let's say two people try 33% of the exam, getting an overall mark in
the exam of 25%, and they already have a combined (below average)
60% in the tests+portfolio. They are still getting a passing mark
on the module.

But... realistically, if two people spend a combined 16 person-hours
and are only able to _try_ 1/3 of the questions, then a passing mark
is about right.

The practise questions seemed kind of easy
------------------------------------------

Believe it or not, a few people got a lot done in the practise questions,
tried to solve most of them, and were mostly correct. The exam is written
so that we think some people _could_ get 100% in 8 hours, and based on
various submissions there are definitely people who could do that.

It is common to have a big split between people who think modules
are too easy versus too hard, and that is true of this course too.


I'm better at coding than my partner. Will we get the same mark?
----------------------------------------------------------------

From an assessment point of view, we already have a balance between
individual ability in mid-terms and portfolio, versus group ability
in the exam. It is _expected_ that most teams will have a (slightly)
stronger and weaker partner, as that is just how life is. If one
person is better at the fundamentals, then they would have got
higher marks in the MCQs.

Ultimately engineering is an applied and group-oriented
practise. As long as both people are trying to contribute,
we do not differentiate on this particular exercise.


I'm worried my partner won't do anything
----------------------------------------

If your partner is doing pretty much nothing, then that is a
different matter. If people are given the chance to contribute,
but choose not to, then there may be grounds for differential
marking. However, this is exceptional, and would need to be
dealt with on a case-by-case bases. Your git commit history is
useful here to show who was doing what, though there is no
automatic check to see how many commits each member performed.

How can I be sure that the final submission is submitted
--------------------------------------------------------

The final submission is whatever is visible on your master
branch in github in your private repo. To double-check the
contents, two methods are:

- Go to the github website, ensure you are looking at the
  master branch, and check the hash. It should match your
  local hash.

- Perform a fresh clone of your repository from github and
  check the hash. It is also worth compiling everything.

From an assessment point of view, the way we will retrieve
your submission is the equivalent of:
```
$ mkdir fresh-clone
$ cd fresh-clone
$ git clone https://github.com/ELEC40004/elec40004-2019-exam-${TEAM}.git
$ cd elec40004-2019-exam-${TEAM}
$ git checkout master
```
If you perform those steps (changing the value of ${TEAM}), then you
are seeing exactly what we can see.


I don't want to cheat, but I'm worried that...
------------------------------------------------------------

### ...people will read the spec for 8 hours, then start working

Now that the 8 hour limit is a suggestion, this is not an
issue. It would be pretty silly to pretend you were working for
less time than you actually did. Much better just to start when
you start, and if you want to take notes and try to understand
the questions for 8 hours, then just take notes and keep committing
the notes.

This is a weak strategy though - much better to get started on
solving/coding/testing the easier stuff, and it is likely it
will help explain the harder stuff.

### ...people will share code with each other

Unfortunately this is a possibility. However, sharing code
is a risky activity, in many ways. You may be heartened
to know that:

1. The person who wrote the original code is liable for plagiarism
2. People who copy code tend to let others copy it again.
3. People who _need_ to cheat are really bad at it.

Often people think they are only sharing code amongst two
teams, but then one of the teams shares with another team,
and then that team shares with two others. Cheaters tend to chea^H^H^H
share outside the original group, and the team that loses out most
is the one that was actually capable of writing the code.
