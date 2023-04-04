Import("env", "projenv")


def before_upload(source, target, env):
    if "upload" == str(target[0]):
        env.Append(UPLOADERFLAGS=["-e"])


env.AddPreAction("upload", before_upload)
env.AddPreAction("uploadeep", before_upload)
