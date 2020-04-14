[@bs.deriving abstract]
type child_process_result = {
  command: string,
  exitCode: int,
  stdout: string,
  stderr: string,
  isCanceled: bool,
  killed: bool,
  timedOut: bool,
  failed: bool,
};

[@bs.deriving abstract]
type child_process_result_buffer = {
  command: string,
  exitCode: int,
  stdout: Node.Buffer.t,
  stderr: Node.Buffer.t,
  isCanceled: bool,
  killed: bool,
  timedOut: bool,
  failed: bool,
};

[@bs.deriving abstract]
type options = {
  shell: bool,
  [@bs.optional]
  input: string,
  [@bs.optional]
  reject: bool,
  [@bs.optional]
  cwd: string,
  [@bs.optional]
  stdio: string,
  [@bs.optional]
  env: Js.Dict.t(string),
  [@bs.optional]
  encoding: Js.Nullable.t(string)
};

[@bs.module "execa"] external commandSync: string => ~options:options=? => unit => child_process_result = "commandSync";
[@bs.module "execa"] external commandSyncBuffer: string => ~options:options=? => unit => child_process_result_buffer = "commandSync";
