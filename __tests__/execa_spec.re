open Jest;

let () =
  describe(
    "execa",
    ExpectJs.(
      () => {

        let res = Execa.child_process_result(
          ~command="ls __tests__/execa_spec.re",
          ~exitCode=0,
          ~stdout="__tests__/execa_spec.re",
          ~stderr="",
          ~isCanceled=false,
          ~killed=false,
          ~timedOut=false,
          ~failed=false
        );

        test("#commandSync works", () =>
          expect(Execa.commandSync("ls __tests__/execa_spec.re", ()))
          |> toEqual(res)
        );
      }
    ),
  );
