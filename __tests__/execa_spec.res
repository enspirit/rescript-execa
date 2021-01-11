open Jest

let () = describe(
  "execa",
  {
    open ExpectJs
    () => {
      let res = Execa.StringResult.child_process_result(
        ~command="ls __tests__/execa_spec.res",
        ~exitCode=0,
        ~stdout="__tests__/execa_spec.res",
        ~stderr="",
        ~isCanceled=false,
        ~killed=false,
        ~timedOut=false,
        ~failed=false
      )

      test("#commandSync works", () =>
        expect(Execa.commandSync("ls __tests__/execa_spec.res", ()))
        |> toEqual(res)
      )

      let options = Execa.options(~shell=false, ~encoding=Js.Nullable.null, ())
      let res = Execa.BufferResult.child_process_result(
        ~command="ls __tests__/execa_spec.res",
        ~exitCode=0,
        ~stdout=Node.Buffer.fromString("__tests__/execa_spec.res"),
        ~stderr=Node.Buffer.fromString(""),
        ~isCanceled=false,
        ~killed=false,
        ~timedOut=false,
        ~failed=false
      )

      test("#commandSyncBuffer works with options", () =>
        expect(Execa.commandSyncBuffer("ls __tests__/execa_spec.res", ~options, ()))
        |> toEqual(res)
      )
    }
  },
)
